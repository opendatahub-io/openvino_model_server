//*****************************************************************************
// Copyright 2021 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#include "../../custom_node_interface.h"
int execute(const struct CustomNodeTensor* inputs, int inputsLength, struct CustomNodeTensor** outputs, int* outputsLength, const struct CustomNodeParam* params, int paramsLength) {
    return 1;
}

int getInputsInfo(struct CustomNodeTensorInfo** info, int* infoLength, const struct CustomNodeParam* params, int paramsLength) {
    return 2;
}

int getOutputsInfo(struct CustomNodeTensorInfo** info, int* infoLength, const struct CustomNodeParam* params, int paramsLength) {
    return 3;
}

int release(void* ptr) {
    return 4;
}