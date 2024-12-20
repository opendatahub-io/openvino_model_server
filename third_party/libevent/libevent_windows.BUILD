# Libevent is available for use under the following license, commonly known
# as the 3-clause (or "modified") BSD license:
#
# ==============================
# Copyright (c) 2000-2007 Niels Provos <provos@citi.umich.edu>
# Copyright (c) 2007-2012 Niels Provos and Nick Mathewson
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# ==============================
#
# Portions of Libevent are based on works by others, also made available by
# them under the three-clause BSD license above.  The copyright notices are
# available in the corresponding source files; the license is as above.  Here's
# a list:
#
# log.c:
#   Copyright (c) 2000 Dug Song <dugsong@monkey.org>
#   Copyright (c) 1993 The Regents of the University of California.
#
# strlcpy.c:
#   Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
#
# win32select.c:
#   Copyright (c) 2003 Michael A. Davis <mike@datanerds.net>
#
# evport.c:
#   Copyright (c) 2007 Sun Microsystems
#
# ht-internal.h:
#   Copyright (c) 2002 Christopher Clark
#
# minheap-internal.h:
#   Copyright (c) 2006 Maxim Yegorushkin <maxim.yegorushkin@gmail.com>
#
# ==============================
#
# The arc4module is available under the following, sometimes called the
# "OpenBSD" license:
#
#   Copyright (c) 1996, David Mazieres <dm@uun.org>
#   Copyright (c) 2008, Damien Miller <djm@openbsd.org>
#
#   Permission to use, copy, modify, and distribute this software for any
#   purpose with or without fee is hereby granted, provided that the above
#   copyright notice and this permission notice appear in all copies.
#
#   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
#   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
#   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
#   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
#   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
#   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
#   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
# ==============================
#
# The Windows timer code is based on code from libutp, which is
# distributed under this license, sometimes called the "MIT" license.
#
#
# Copyright (c) 2010 BitTorrent, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# ==============================
#
# The wepoll module is available under the following, sometimes called the
# "FreeBSD" license:
#
# Copyright 2012-2020, Bert Belder <bertbelder@gmail.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# ==============================
#
# The ssl-client-mbedtls.c is available under the following license:
#
# Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# This file is part of mbed TLS (https://tls.mbed.org)

# libevent (libevent.org) library.
# from https://github.com/libevent/libevent

package(
    default_visibility = ["//visibility:public"],
)

licenses(["notice"])  # BSD

exports_files(["LICENSE"])

include_files = [
    "libevent/include/evdns.h",
    "libevent/include/event.h",
    "libevent/include/evhttp.h",
    "libevent/include/evrpc.h",
    "libevent/include/evutil.h",
    "libevent/include/event2/buffer.h",
    "libevent/include/event2/bufferevent_struct.h",
    "libevent/include/event2/event.h",
    "libevent/include/event2/http_struct.h",
    "libevent/include/event2/rpc_struct.h",
    "libevent/include/event2/buffer_compat.h",
    "libevent/include/event2/dns.h",
    "libevent/include/event2/event_compat.h",
    "libevent/include/event2/keyvalq_struct.h",
    "libevent/include/event2/tag.h",
    "libevent/include/event2/bufferevent.h",
    "libevent/include/event2/dns_compat.h",
    "libevent/include/event2/event_struct.h",
    "libevent/include/event2/listener.h",
    "libevent/include/event2/tag_compat.h",
    "libevent/include/event2/bufferevent_compat.h",
    "libevent/include/event2/dns_struct.h",
    "libevent/include/event2/http.h",
    "libevent/include/event2/rpc.h",
    "libevent/include/event2/thread.h",
    "libevent/include/event2/event-config.h",
    "libevent/include/event2/http_compat.h",
    "libevent/include/event2/rpc_compat.h",
    "libevent/include/event2/util.h",
    "libevent/include/event2/visibility.h",
]

WINDOWS_LIB_PATH = "c:\\opt\\libevent\\*"

lib_files = [
    "libevent/lib/event.lib",
    "libevent/lib/event_core.lib",
    "libevent/lib/event_extra.lib",
    # TODO: windows compilation does not produce this: "libevent/lib/libevent_pthreads.lib",
]

genrule(
    name = "libevent-srcs",
    outs = include_files + lib_files,
    cmd = "\n".join([
        "export INSTALL_DIR=$$(pwd)/$(@D)/libevent",
        "export TMP_DIR=$$(mktemp -d -t libevent.XXXXXX)",
        "mkdir -p $$TMP_DIR",
        "cp -R $$(pwd | sed -E 's:(/sandbox/.+)::g')/external/com_github_libevent_libevent/* $$TMP_DIR",
        "cd $$TMP_DIR",
        "./autogen.sh",
        "./configure --prefix=$$INSTALL_DIR CFLAGS=-fPIC CXXFLAGS=-fPIC --enable-shared=no --disable-openssl",
        "make install",
        "rm -rf $$TMP_DIR",
    ]),
    # TODO windows: compile the libevent here instead of copying from hardcoded path, find a way to execute more than one command in cmd_bat on windows
    cmd_bat = "xcopy /R /E /Y /F c:\\opt\\libevent\\ %cd%\\$(@D)\\libevent\\",
)

cc_library(
    name = "libevent",
    srcs = [
        "libevent/lib/libevent.lib",
    ],
    hdrs = include_files,
    includes = ["libevent/include"],
    linkstatic = 1,
)

filegroup(
    name = "libevent-files",
    srcs = include_files + lib_files,
)
