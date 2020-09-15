/*
* Copyright 2020-2020, Synopsys, Inc.
* All rights reserved.
*
* This source code is licensed under the BSD-3-Clause license found in
* the LICENSE file in the root directory of this source tree.
*
*/

#ifndef _MLI_KRN_SOFTMAX_DECL_H_
#define _MLI_KRN_SOFTMAX_DECL_H_

#include "mli_config.h"
#include "mli_types.h"
#include "mli_prv_tensor.h"

namespace mli {
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

template <typename io_T>
static mli_status mli_krn_softmax_fx_run(const mli_tensor *in,
        const mli_softmax_cfg* cfg, mli_tensor *out);

static mli_status mli_krn_softmax_sa8_run(const mli_tensor *in,
        const mli_softmax_cfg* cfg, mli_tensor *out);

} // namespace ref

////////////////////////////////////////////////////////////////////////////////
// DSP
////////////////////////////////////////////////////////////////////////////////
namespace dsp {

template <typename io_T>
static MLI_FORCE_INLINE mli_status mli_krn_softmax_fx_run(const mli_tensor *in,
        const mli_softmax_cfg* cfg, mli_tensor *out);

static MLI_FORCE_INLINE mli_status mli_krn_softmax_sa8_run(const mli_tensor *in,
        const mli_softmax_cfg* cfg, mli_tensor *out);

} // namespace dsp

////////////////////////////////////////////////////////////////////////////////
// VDSP
////////////////////////////////////////////////////////////////////////////////
namespace vdsp {

template <typename io_T>
static MLI_FORCE_INLINE mli_status mli_krn_softmax_fx_run(const mli_tensor *in,
        const mli_softmax_cfg* cfg, mli_tensor *out);

static MLI_FORCE_INLINE mli_status mli_krn_softmax_sa8_run(const mli_tensor *in,
        const mli_softmax_cfg* cfg, mli_tensor *out);

} // namespace vdsp

} // namespace krn
} // namespace mli

#endif // _MLI_KRN_SOFTMAX_DECL_H_