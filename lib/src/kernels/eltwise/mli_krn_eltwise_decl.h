/*
* Copyright 2020-2020, Synopsys, Inc.
* All rights reserved.
*
* This source code is licensed under the BSD-3-Clause license found in
* the LICENSE file in the root directory of this source tree.
*
*/

#ifndef _MLI_KRN_ELTWISE_ADD_DECL_REF_H_
#define _MLI_KRN_ELTWISE_ADD_DECL_REF_H_

#include "mli_config.h"
#include "mli_types.h"
#include "mli_prv_quant.h"

namespace mli {
typedef enum {
    ELTWISE_ADD = 0,
    ELTWISE_SUB,
    ELTWISE_MUL,
    ELTWISE_MAX,
    ELTWISE_MIN
} mli_eltwise_type;

namespace krn {
////////////////////////////////////////////////////////////////////////////////
// Functions (in *_ref/*_dsp/*vdsp) that can be called from outside their own
// file must be declared here. This includes all overloads. For example, if we
// have: io_T f(io_T a) and int8_t f(int8_t a), then both must be declared.
// Not doing so, can cause the compiler to use the wrong overload.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// REF
////////////////////////////////////////////////////////////////////////////////
namespace ref {

template <typename io_T, mli_eltwise_type func_type, bool convert = false>
static MLI_FORCE_INLINE void eltwise_prepare_and_run(
        const mli_tensor *in1,
        const mli_tensor *in2,
        mli_tensor *out);

template <typename io_T, mli_eltwise_type func_type, bool convert = false>
static MLI_FORCE_INLINE void eltwise_op_basic(
        const generic_tensor_private_t<MLI_PTR(io_T)> *in1,
        const generic_tensor_private_t<MLI_PTR(io_T)> *in2,
        generic_tensor_private_t<MLI_OUT_PTR(io_T)> *out,
        const int op1_size,
        const int op2_size,
        const int mul_out_shift,
        const struct s8asym_quant_params *in_quant_params = nullptr,
        const struct s8asym_quant_params *out_quant_params = nullptr);

template <typename in_T, typename out_T, mli_eltwise_type func_type, bool convert>
static MLI_FORCE_INLINE out_T eltwise_perform_operation(
        const in_T op1,
        const in_T op2,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale_factor,
        const int shift,
        bool reverse_sub);

template <typename io_T, mli_eltwise_type func_type, bool convert>
MLI_FORCE_INLINE void eltwise_innerloop(
        const MLI_PTR(io_T) op1_ptr,
        const MLI_PTR(io_T) op2_ptr,
        MLI_PTR(io_T) out_ptr,
        int idx1,
        int idx2,
        int idx_out,
        const int count,
        const bool scalar_op,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale,
        const int shift,
        const bool reverse_sub);
} // namespace ref

////////////////////////////////////////////////////////////////////////////////
// DSP
////////////////////////////////////////////////////////////////////////////////
namespace dsp {

template <typename io_T, mli_eltwise_type func_type, bool convert = false>
static MLI_FORCE_INLINE void eltwise_op_basic(
        const generic_tensor_private_t<MLI_PTR(io_T)> *in1,
        const generic_tensor_private_t<MLI_PTR(io_T)> *in2,
        generic_tensor_private_t<MLI_OUT_PTR(io_T)> *out,
        const int op1_size,
        const int op2_size,
        const int mul_out_shift,
        const struct s8asym_quant_params *in_quant_params = nullptr,
        const struct s8asym_quant_params *out_quant_params = nullptr);

} // namespace dsp

////////////////////////////////////////////////////////////////////////////////
// VDSP
////////////////////////////////////////////////////////////////////////////////
namespace vdsp {

template <typename in_T, typename out_T, mli_eltwise_type func_type, bool convert>
static MLI_FORCE_INLINE out_T eltwise_perform_operation(
        const in_T op1,
        const in_T op2,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale_factor,
        const int shift,
        bool reverse_sub);

#if defined(__Xvec_width)
template <>
MLI_FORCE_INLINE vNx2short_t eltwise_perform_operation<vNx2short_t, vNx2short_t, ELTWISE_ADD, false>(
        const vNx2short_t op1,
        const vNx2short_t op2,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale_factor,
        const int shift,
        bool reverse_sub);

template <>
MLI_FORCE_INLINE vNx4char_t eltwise_perform_operation<vNx4char_t, vNx4char_t, ELTWISE_ADD, false>(
        const vNx4char_t op1,
        const vNx4char_t op2,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale_factor,
        const int shift,
        bool reverse_sub);

template <>
MLI_FORCE_INLINE vNx4char_t eltwise_perform_operation<vNx4char_t, vNx4char_t, ELTWISE_ADD, true>(
        const vNx4char_t op1,
        const vNx4char_t op2,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale_factor,
        const int shift,
        bool reverse_sub);
#endif

template <typename io_T, mli_eltwise_type func_type, bool convert>
MLI_FORCE_INLINE void eltwise_innerloop(
        const MLI_PTR(io_T) op1_ptr,
        const MLI_PTR(io_T) op2_ptr,
        MLI_PTR(io_T) out_ptr,
        int idx1,
        int idx2,
        int idx_out,
        const int count,
        const bool scalar_op,
        const int16_t in_offset,
        const int16_t out_offset,
        const int16_t scale,
        const int shift,
        const bool reverse_sub);
} // namespace vdsp

} // namespace krn
} // namespace mli

#endif // _MLI_KRN_ELTWISE_ADD_DECL_REF_H_
