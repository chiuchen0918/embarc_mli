/*
* Copyright 2021, Synopsys, Inc.
* All rights reserved.
*
* This source code is licensed under the BSD-3-Clause license found in
* the LICENSE file in the root directory of this source tree.
*
*/

#ifndef _MLI_KRN_AVEPOOL_HWC_DSP_H_
#define _MLI_KRN_AVEPOOL_HWC_DSP_H_

#include "mli_krn_reduce_sum2d.h"
#include "mli_prv_load_store.h"
#include "mli_prv_dsp.h"
#include "mli_math.h"
#include "mli_mem_info.h"

namespace mli {
namespace krn {
namespace dsp {

static MLI_FORCE_INLINE void compute_avepool_func(
        const MLI_PTR(int8_t) __restrict in,
        MLI_OUT_PTR(int8_t) __restrict out,
        const int16_t mul,
        const int width,
        const int height,
        const int col_mem_stride,
        const int row_mem_stride,
        const int32_t zp,
        const int shift_value,
        const int channels)
{
    __v2i32_t accu = mli_prv_init_accu_with_bias_v<__v2i32_t>(zp, shift_value);

    accu = mli::krn::reduce_sum2D_v(in, mul, accu, width, height, col_mem_stride, row_mem_stride);

    mli_prv_clip_and_store_output_v(out, accu, shift_value, channels);
}

static MLI_FORCE_INLINE void compute_avepool_func(
        const MLI_PTR(int16_t) __restrict in,
        MLI_OUT_PTR(int16_t) __restrict out,
        const int16_t mul,
        const int width,
        const int height,
        const int col_mem_stride,
        const int row_mem_stride,
        const int32_t zp,
        const int shift_value,
        const int channels)
{
    v2accum40_t accu = mli_prv_init_accu_with_bias_v<v2accum40_t>(zp, shift_value);

    accu = mli::krn::reduce_sum2D_v(in, mul, accu, width, height, col_mem_stride, row_mem_stride);

    mli_prv_clip_and_store_output_v(out, accu, shift_value, channels);
}

static MLI_FORCE_INLINE void compute_avepool_func(
        const MLI_PTR(int8_t) __restrict in,
        MLI_OUT_PTR(int32_t) __restrict out,
        const int16_t mul,
        const int width,
        const int height,
        const int col_mem_stride,
        const int row_mem_stride,
        const int32_t zp,
        const int shift_value,
        const int channels) {

    __v2i32_t accu = mli_prv_init_accu_with_bias_v<__v2i32_t>(zp, shift_value);

    accu = mli::krn::reduce_sum2D_v(in, mul, accu, width, height, col_mem_stride, row_mem_stride);

    // Cast result to output type, no shift and store.
    // out is expected equal or wider than acc_t
    mli_prv_clip_and_store_output_v(out, accu, shift_value, channels);
}

template<typename i_T, typename o_T, int fixed_kernel_size, bool varying_kernel>
static MLI_FORCE_INLINE void compute_avepool(
        const MLI_PTR(i_T) __restrict in,
        MLI_OUT_PTR(o_T) __restrict out,
        const int16_t mul,
        const int width,
        const int height,
        const int col_mem_stride,
        const int row_mem_stride,
        const int32_t zp,
        const int shift_value,
        const int channels) {

    compute_avepool_func(in, out, mul, width, height, col_mem_stride, row_mem_stride, zp ,shift_value, channels);
}

} // namespace dsp
} // namespace krn
} // namespace mli

#endif // _MLI_KRN_AVEPOOL_HWC_DSP_H_