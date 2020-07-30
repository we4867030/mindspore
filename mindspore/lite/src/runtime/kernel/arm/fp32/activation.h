/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_FP32_ACTIVATION_H_
#define MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_FP32_ACTIVATION_H_

#include <vector>
#include "src/lite_kernel.h"
#include "src/runtime/kernel/arm/opclib/fp32/activation.h"

namespace mindspore::kernel {
class ActivationCPUKernel : public LiteKernel {
 public:
  ActivationCPUKernel(OpParameter *param, const std::vector<lite::tensor::Tensor *> &inputs,
                      const std::vector<lite::tensor::Tensor *> &outputs, const lite::Context *ctx)
      : LiteKernel(param, inputs, outputs), thread_count_(ctx->threadNum) {
    type_ = (reinterpret_cast<ActivationParameter *>(param))->type_;
    alpha_ = (reinterpret_cast<ActivationParameter *>(param))->alpha_;
  }
  ~ActivationCPUKernel() override = default;

  int Init() override;
  int ReSize() override;
  int Run() override;
  int DoActivation(int task_id);

 private:
  int thread_count_;
  int type_;
  float alpha_;
};
}  // namespace mindspore::kernel

#endif  // MINDSPORE_LITE_SRC_RUNTIME_KERNEL_ARM_FP32_ACTIVATION_H_