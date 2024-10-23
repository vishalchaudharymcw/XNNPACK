// Auto-generated file. Do not edit!
//   Template: src/f32-qs8-vcvt/scalar-imagic.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include "xnnpack/common.h"
#include "xnnpack/math.h"
#include "xnnpack/vcvt.h"

void xnn_f16_qs8_vcvt_ukernel__scalar_imagic_u2(
    size_t batch,
    const xnn_float16* input,
    int8_t* output,
    const struct xnn_f16_qs8_cvt_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(batch != 0);
  assert(batch % sizeof(xnn_float16) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const xnn_float16* i = input;
  const float vscale = xnn_float16_to_float(params->scalar.scale);
  const float vmagic_bias = 12582912.0f;
  const float output_min_less_zero_point = (float) ((int32_t) -128 - (int32_t) params->scalar.output_zero_point);
  const float output_max_less_zero_point = (float) ((int32_t) 127 - (int32_t) params->scalar.output_zero_point);
  const int32_t vmagic_min = (int32_t) float_as_uint32(vmagic_bias + output_min_less_zero_point);
  const int32_t vmagic_max = (int32_t) float_as_uint32(vmagic_bias + output_max_less_zero_point);
  const int32_t vmagic_bias_less_zero_point = INT32_C(0x4B400000) - (int32_t) params->scalar.output_zero_point;

  for (; batch >= 2 * sizeof(xnn_float16); batch -= 2 * sizeof(xnn_float16)) {
    float vx0 = xnn_float16_to_float(i[0]);
    float vx1 = xnn_float16_to_float(i[1]);
    i += 2;

    vx0 *= vscale;
    vx1 *= vscale;

    vx0 += vmagic_bias;
    vx1 += vmagic_bias;

    int32_t vy0 = (int32_t) float_as_uint32(vx0);
    int32_t vy1 = (int32_t) float_as_uint32(vx1);

    vy0 = math_max_s32(vy0, vmagic_min);
    vy1 = math_max_s32(vy1, vmagic_min);

    vy0 = math_min_s32(vy0, vmagic_max);
    vy1 = math_min_s32(vy1, vmagic_max);

    vy0 -= vmagic_bias_less_zero_point;
    vy1 -= vmagic_bias_less_zero_point;

    output[0] = (int8_t) vy0;
    output[1] = (int8_t) vy1;
    output += 2;
  }
  if XNN_UNLIKELY(batch != 0) {
    float vx = xnn_float16_to_float(*i);
    vx *= vscale;
    vx += vmagic_bias;

    int32_t vy = (int32_t) float_as_uint32(vx);
    vy = math_max_s32(vy, vmagic_min);
    vy = math_min_s32(vy, vmagic_max);
    vy -= vmagic_bias_less_zero_point;

    *output = (int8_t) vy;
  }
}
