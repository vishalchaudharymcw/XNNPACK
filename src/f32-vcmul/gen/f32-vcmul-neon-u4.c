// Auto-generated file. Do not edit!
//   Template: src/f32-vcmul/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/common.h>
#include <xnnpack/vbinary.h>


void xnn_f32_vcmul_ukernel__neon_u4(
    size_t batch,
    const float* input_a,
    const float* input_b,
    float* output,
    const union xnn_f32_default_params* params) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  const float* ar = input_a;
  const float* ai = (const float*) ((uintptr_t) input_a + batch);
  const float* br = input_b;
  const float* bi = (const float*) ((uintptr_t) input_b + batch);
  float* or = output;
  float* oi = (float*) ((uintptr_t) output + batch);
  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const float32x4_t var = vld1q_f32(ar); ar += 4;
    const float32x4_t vai = vld1q_f32(ai); ai += 4;
    const float32x4_t vbr = vld1q_f32(br); br += 4;
    const float32x4_t vbi = vld1q_f32(bi); bi += 4;

    float32x4_t vaccr = vmulq_f32(var, vbr);
    float32x4_t vacci = vmulq_f32(var, vbi);

    vaccr = vmlsq_f32(vaccr, vai, vbi);
    vacci = vmlaq_f32(vacci, vai, vbr);

    vst1q_f32(or, vaccr); or += 4;
    vst1q_f32(oi, vacci); oi += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    const float32x4_t var = vld1q_f32(ar); ar += 4;
    const float32x4_t vai = vld1q_f32(ai); ai += 4;
    const float32x4_t vbr = vld1q_f32(br); br += 4;
    const float32x4_t vbi = vld1q_f32(bi); bi += 4;

    float32x4_t vaccr = vmulq_f32(var, vbr);
    float32x4_t vacci = vmulq_f32(var, vbi);

    vaccr = vmlsq_f32(vaccr, vai, vbi);
    vacci = vmlaq_f32(vacci, vai, vbr);

    float32x2_t vaccr_lo = vget_low_f32(vaccr);
    float32x2_t vacci_lo = vget_low_f32(vacci);
    if (batch & (2 * sizeof(float))) {
      vst1_f32(or, vaccr_lo); or += 2;
      vst1_f32(oi, vacci_lo); oi += 2;
      vaccr_lo = vget_high_f32(vaccr);
      vacci_lo = vget_high_f32(vacci);
    }
    if (batch & (1 * sizeof(float))) {
      vst1_lane_f32(or, vaccr_lo, 0);
      vst1_lane_f32(oi, vacci_lo, 0);
    }
  }
}
