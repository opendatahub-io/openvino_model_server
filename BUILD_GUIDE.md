# OVMS Multi-Architecture Build Guide

## Overview

This guide helps you build OpenVINO Model Server (OVMS) with multi-architecture support for amd64, s390x, and ppc64le.

## Prerequisites

### Hardware Requirements

**Minimum recommended (for single-arch amd64 build):**
- **Disk Space**: 50GB free (build artifacts + Docker layers)
- **RAM**: 16GB (8GB minimum, but builds may fail with OOM)
- **CPU**: 4 cores minimum (8+ cores recommended)
- **Build Time**: 2-4 hours for full build

**For multi-arch build (all 3 architectures):**
- **Disk Space**: 100GB free
- **RAM**: 16GB minimum
- **CPU**: 8+ cores highly recommended
- **Build Time**: 6-12 hours total (with QEMU emulation)

### Software Requirements

1. **Docker Desktop** (or Docker Engine + buildx plugin)
   - Version 20.10+ with buildx support
   - Enable containerd image store for better performance

2. **Buildx Builder** with multi-platform support
   ```bash
   docker buildx create --name ovms-multiarch --driver docker-container --use
   docker buildx inspect ovms-multiarch --bootstrap
   ```

3. **Git** for source checkout

## Quick Start

### Option 1: Single Architecture Build (Recommended for Testing)

Build just for your current architecture to verify everything works:

```bash
# Build only amd64
make docker_build BASE_OS=redhat DIST_OS=redhat

# Or build for a specific single arch with buildx
docker buildx build \
  --builder ovms-multiarch \
  --platform linux/amd64 \
  --file Dockerfile.redhat \
  --build-arg BASE_OS=redhat \
  --build-arg JOBS=8 \
  --load \
  --tag ovms:test-amd64 \
  .
```

### Option 2: Multi-Arch Build (Production)

```bash
# Build for all architectures and push to registry
make docker_build_multiarch \
  BASE_OS=redhat \
  DIST_OS=redhat \
  OVMS_CPP_DOCKER_IMAGE=quay.io/yourusername/openvino_model_server \
  OVMS_CPP_IMAGE_TAG=v2026.3-multiarch
```

### Option 3: Per-Architecture Build (For Debugging)

Build each architecture separately:

```bash
# Build each separately
for arch in amd64 s390x ppc64le; do
  docker buildx build \
    --builder ovms-multiarch \
    --platform linux/$arch \
    --file Dockerfile.redhat \
    --build-arg BASE_OS=redhat \
    --build-arg GPU=0 \
    --build-arg JOBS=8 \
    --tag ovms:test-$arch \
    --load \
    .
done
```

## Build Optimization Tips

### 1. Use Build Cache

Docker buildx maintains a build cache. Leverage it:

```bash
docker buildx build \
  --cache-from type=local,src=/tmp/.buildx-cache \
  --cache-to type=local,dest=/tmp/.buildx-cache \
  ...
```

### 2. Reduce Parallel Jobs for Memory-Constrained Systems

The `JOBS` parameter controls parallel compilation:

```bash
# For systems with 8GB RAM
--build-arg JOBS=4

# For systems with 16GB+ RAM
--build-arg JOBS=8
```

### 3. Build Only What You Need

Skip GPU support for non-x86 or if you don't need it:

```bash
--build-arg GPU=0
```

Skip Python bindings if not needed:

```bash
--build-arg PYTHON_DISABLE=1 --build-arg MEDIAPIPE_DISABLE=1
```

### 4. Use Stage-Specific Builds

Build up to a specific stage to debug:

```bash
docker buildx build \
  --target=base_build \  # or 'build', 'pkg', 'release'
  ...
```

## Common Build Issues and Solutions

### Issue 1: "Out of Memory" / Build Killed

**Symptoms:**
- Build process killed without error
- Container exits with code 137
- System becomes unresponsive during build

**Solutions:**
1. Reduce parallel jobs: `--build-arg JOBS=2`
2. Increase Docker Desktop memory limit (Settings → Resources → Memory)
3. Build in stages and clean up between stages:
   ```bash
   docker system prune -a -f
   ```

### Issue 2: "No Space Left on Device"

**Symptoms:**
- Build fails with disk space errors
- Docker pull/push fails

**Solutions:**
1. Clean up Docker:
   ```bash
   docker system prune -a -f --volumes
   docker buildx prune -a -f
   ```
2. Increase Docker Desktop disk image size (Settings → Resources → Disk)
3. Change Docker data directory to a larger drive

### Issue 3: Bazel Build Timeout (s390x/ppc64le)

**Symptoms:**
- OpenVINO compilation hangs or times out on non-x86 architectures

**Solutions:**
1. Already implemented in Dockerfile: reduced JOBS to 8 for s390x/ppc64le
2. If still timing out, manually override:
   ```bash
   # Edit Dockerfile.redhat line ~119, change to:
   echo "export ARCH_JOBS=4" > /tmp/jobs_override.sh
   ```

### Issue 4: QEMU Emulation is Very Slow

**Symptoms:**
- s390x/ppc64le builds take 10+ hours
- System resources underutilized

**Reality Check:**
- QEMU emulation for cross-arch builds is inherently slow (5-10x slower than native)
- This is expected behavior, not a bug

**Solutions:**
1. **Use GitHub Actions** (recommended): Let CI build on GitHub's infrastructure
2. **Use native hardware**: Build s390x on IBM Z, ppc64le on POWER systems
3. **Use cloud build services**: 
   - AWS CodeBuild (supports multi-arch)
   - Google Cloud Build
   - Quay.io (auto-builds on push)

### Issue 5: "Cannot connect to Docker daemon"

**Symptoms:**
- `make docker_build_multiarch` fails immediately

**Solutions:**
1. Start Docker Desktop: `open -a Docker`
2. Wait for Docker to fully start (~30 seconds)
3. Verify: `docker info`

## Recommended Build Strategy

### For Development/Testing

**Don't build locally** - it's time-consuming and resource-intensive.

Instead:
1. **Push to GitHub**: The multi-arch workflow will build automatically
2. **Use pre-built images**: Pull from quay.io/opendatahub/openvino_model_server
3. **Build single-arch only**: Just build amd64 locally for testing

### For Production

**Use CI/CD pipeline:**

1. **GitHub Actions** (already configured in `.github/workflows/multiarch-build.yaml`):
   - Automatically builds on push to multiarch/* branches
   - Builds all 3 architectures in parallel
   - Pushes to Quay.io registry
   - Verifies manifest integrity

2. **Required secrets** in GitHub repo:
   - `QUAY_USERNAME`: Your Quay.io username
   - `QUAY_PASSWORD`: Your Quay.io password or robot token

## Build Time Estimates

Based on GitHub Actions runners (not local QEMU emulation):

| Architecture | Build Time | Notes |
|--------------|-----------|--------|
| amd64 | 1-2 hours | Native x86_64 build |
| s390x | 3-5 hours | QEMU emulation (slow) |
| ppc64le | 3-5 hours | QEMU emulation (slow) |
| **Total (parallel)** | **5-6 hours** | GitHub Actions runs in parallel |

## Testing Your Build

### 1. Verify Image Exists

```bash
docker images | grep ovms
```

### 2. Run Basic Version Check

```bash
docker run --rm ovms:test-amd64 --version
```

### 3. Test Multi-Arch Manifest

```bash
# Inspect manifest
docker buildx imagetools inspect quay.io/yourusername/openvino_model_server:v2026.3-multiarch

# Should show all three architectures:
# - linux/amd64
# - linux/s390x
# - linux/ppc64le
```

### 4. Test Architecture-Specific Pull

```bash
for arch in amd64 s390x ppc64le; do
  echo "Testing $arch..."
  docker pull --platform linux/$arch \
    quay.io/yourusername/openvino_model_server:v2026.3-multiarch
done
```

## What If the Build Still Fails?

### Fallback Option: Use Binary OpenVINO Package

Instead of building OpenVINO from source (which is slow), use pre-built binaries:

```bash
docker buildx build \
  --build-arg ov_use_binary=1 \
  --build-arg DLDT_PACKAGE_URL=<openvino-binary-url> \
  ...
```

**Note:** Binary packages may not be available for s390x/ppc64le, so source builds are necessary for those architectures.

### Contact for Help

If you encounter issues not covered here:

1. **Check existing issues**: https://github.com/opendatahub-io/openvino_model_server/issues
2. **File a new issue** with:
   - Your system specs (CPU, RAM, OS)
   - Docker version: `docker version`
   - Full build log (use `--progress=plain`)
   - Error messages

## Next Steps

After a successful build:

1. **Update image references** in opendatahub-tests repository
2. **Run test suite** to verify functionality on each architecture
3. **Tag release version** and push to production registry
4. **Update documentation** with new image digest

## Additional Resources

- [Docker Buildx Multi-Platform Docs](https://docs.docker.com/build/building/multi-platform/)
- [OpenVINO Build Documentation](https://docs.openvino.ai/2025/get-started/install-openvino.html)
- [OVMS Multi-Arch Implementation Guide](/Users/kpunwatk/opendatahub-tests/OVMS_MULTIARCH_BUILD_GUIDE.md)
