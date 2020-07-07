# Copyright 2020 Huawei Technologies Co., Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ============================================================================

"""BesselI1e op"""
from mindspore.ops.op_info_register import op_info_register, TBERegOp, DataType

bessel_i1e_op_info = TBERegOp("BesselI1e") \
    .fusion_type("ELEMWISE") \
    .async_flag(False) \
    .binfile_name("bessel_i1e.so") \
    .compute_cost(10) \
    .kernel_name("bessel_i1e") \
    .partial_flag(True) \
    .op_pattern("formatAgnostic") \
    .input(0, "x", False, "required", "all") \
    .output(0, "y", False, "required", "all") \
    .dtype_format(DataType.F16_None, DataType.F16_None) \
    .dtype_format(DataType.F32_None, DataType.F32_None) \
    .get_op_info()


@op_info_register(bessel_i1e_op_info)
def _bessel_i1e_tbe():
    """BesselI1e TBE register"""
    return
