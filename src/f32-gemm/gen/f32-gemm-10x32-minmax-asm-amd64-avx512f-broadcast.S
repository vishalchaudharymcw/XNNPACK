// Copyright 2025 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include "xnnpack/assembly.h"

BEGIN_FUNCTION xnn_f32_gemm_minmax_ukernel_10x32__asm_amd64_avx512f_broadcast

      .intel_syntax noprefix

      # Free up GP registers.
      push rbx
      push rbp
      push r15
      push r14
      push r13
      push r12

      # load params to free up a GP registers
      mov r13, [rsp + 80] # params
      vbroadcastss zmm0, DWORD PTR [r13]
      vbroadcastss zmm1, DWORD PTR [r13 + 4]

      # Load c pointer.
      mov r10, [rsp + 56]
      # Load cm_stride.
      mov r11, [rsp + 64]

      # Allocate some space on the stack.
      sub rsp, 192
      # Write rsi (a pointer) to the stack as we need the register.
      mov [rsp], rcx
      # Write r10 (c pointer) to the stack as we need the register.
      mov [rsp + 8], r10

      # Clamp a & c pointers if mr <= 1
      mov rax, rcx
      add rax, r8
      mov r13, r10
      add r13, r11
      cmp rdi, 1
      cmovle rax, rcx
      cmovle r13, r10

      mov [rsp + 16], rax
      mov [rsp + 24], r13

      # Clamp a & c pointers if mr <= 2
      mov rcx, rax
      add rcx, r8
      mov r10, r13
      add r10, r11
      cmp rdi, 2
      cmovle rcx, rax
      cmovle r10, r13

      mov [rsp + 32], rcx
      mov [rsp + 40], r10

      # Clamp a & c pointers if mr <= 3
      mov rax, rcx
      add rax, r8
      mov r13, r10
      add r13, r11
      cmp rdi, 3
      cmovle rax, rcx
      cmovle r13, r10

      mov [rsp + 48], rax
      mov [rsp + 56], r13

      # Clamp a & c pointers if mr <= 4
      mov rcx, rax
      add rcx, r8
      mov r10, r13
      add r10, r11
      cmp rdi, 4
      cmovle rcx, rax
      cmovle r10, r13

      mov [rsp + 64], rcx
      mov [rsp + 72], r10

      # Clamp a & c pointers if mr <= 5
      mov rax, rcx
      add rax, r8
      mov r13, r10
      add r13, r11
      cmp rdi, 5
      cmovle rax, rcx
      cmovle r13, r10

      mov [rsp + 80], rax
      mov [rsp + 88], r13

      # Clamp a & c pointers if mr <= 6
      mov rcx, rax
      add rcx, r8
      mov r10, r13
      add r10, r11
      cmp rdi, 6
      cmovle rcx, rax
      cmovle r10, r13

      mov [rsp + 96], rcx
      mov [rsp + 104], r10

      # Clamp a & c pointers if mr <= 7
      mov rax, rcx
      add rax, r8
      mov r13, r10
      add r13, r11
      cmp rdi, 7
      cmovle rax, rcx
      cmovle r13, r10

      mov [rsp + 112], rax
      mov [rsp + 120], r13

      # Clamp a & c pointers if mr <= 8
      mov rcx, rax
      add rcx, r8
      mov r10, r13
      add r10, r11
      cmp rdi, 8
      cmovle rcx, rax
      cmovle r10, r13

      mov [rsp + 128], rcx
      mov [rsp + 136], r10

      # Clamp a & c pointers if mr <= 9
      mov rax, rcx
      add rax, r8
      mov r13, r10
      add r13, r11
      cmp rdi, 9
      cmovle rax, rcx
      cmovle r13, r10

      mov [rsp + 144], rax
      mov [rsp + 152], r13

outer_loop:
      # Initialize k counter.
      mov r11, 0
      # Read a pointers from stack into GP registers.
      mov rcx, [rsp + 0]
      mov rax, [rsp + 16]
      mov r15, [rsp + 32]
      mov r14, [rsp + 48]
      mov r12, [rsp + 64]
      mov r10, [rsp + 80]
      mov r13, [rsp + 96]
      mov rbx, [rsp + 112]
      mov rbp, [rsp + 128]
      mov r8, [rsp + 144]

      # Initialize accumulators with the biases.
      vmovaps  zmm7, [r9 + 0]
      vmovaps  zmm21, [r9 + 64]
      vmovaps zmm8, zmm7
      vmovaps zmm9, zmm7
      vmovaps zmm14, zmm7
      vmovaps zmm15, zmm7
      vmovaps zmm16, zmm7
      vmovaps zmm17, zmm7
      vmovaps zmm18, zmm7
      vmovaps zmm19, zmm7
      vmovaps zmm20, zmm7
      vmovaps zmm22, zmm21
      vmovaps zmm23, zmm21
      vmovaps zmm24, zmm21
      vmovaps zmm25, zmm21
      vmovaps zmm26, zmm21
      vmovaps zmm27, zmm21
      vmovaps zmm28, zmm21
      vmovaps zmm29, zmm21
      vmovaps zmm30, zmm21
      add r9, 128

inner_loop:
      vmovaps  zmm10, [r9 + 0]
      vmovaps  zmm11, [r9 + 64]
      add r9, 128
      vbroadcastss zmm2, DWORD PTR [rcx + r11]
      vfmadd231ps  zmm7, zmm2, zmm10
      vfmadd231ps  zmm21, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [rax + r11]
      vfmadd231ps  zmm8, zmm2, zmm10
      vfmadd231ps  zmm22, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [r15 + r11]
      vfmadd231ps  zmm9, zmm2, zmm10
      vfmadd231ps  zmm23, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [r14 + r11]
      vfmadd231ps  zmm14, zmm2, zmm10
      vfmadd231ps  zmm24, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [r12 + r11]
      vfmadd231ps  zmm15, zmm2, zmm10
      vfmadd231ps  zmm25, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [r10 + r11]
      vfmadd231ps  zmm16, zmm2, zmm10
      vfmadd231ps  zmm26, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [r13 + r11]
      vfmadd231ps  zmm17, zmm2, zmm10
      vfmadd231ps  zmm27, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [rbx + r11]
      vfmadd231ps  zmm18, zmm2, zmm10
      vfmadd231ps  zmm28, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [rbp + r11]
      vfmadd231ps  zmm19, zmm2, zmm10
      vfmadd231ps  zmm29, zmm2, zmm11
      vbroadcastss zmm2, DWORD PTR [r8 + r11]
      vfmadd231ps  zmm20, zmm2, zmm10
      vfmadd231ps  zmm30, zmm2, zmm11

      add r11, 4
      cmp rdx, r11
      jne inner_loop
inner_loop_end:
      # Min/max clamping.
      vminps  zmm7, zmm1, zmm7
      vminps  zmm8, zmm1, zmm8
      vminps  zmm9, zmm1, zmm9
      vminps  zmm14, zmm1, zmm14
      vminps  zmm15, zmm1, zmm15
      vminps  zmm16, zmm1, zmm16
      vminps  zmm17, zmm1, zmm17
      vminps  zmm18, zmm1, zmm18
      vminps  zmm19, zmm1, zmm19
      vminps  zmm20, zmm1, zmm20
      vminps  zmm21, zmm1, zmm21
      vminps  zmm22, zmm1, zmm22
      vminps  zmm23, zmm1, zmm23
      vminps  zmm24, zmm1, zmm24
      vminps  zmm25, zmm1, zmm25
      vminps  zmm26, zmm1, zmm26
      vminps  zmm27, zmm1, zmm27
      vminps  zmm28, zmm1, zmm28
      vminps  zmm29, zmm1, zmm29
      vminps  zmm30, zmm1, zmm30
      vmaxps  zmm7, zmm0, zmm7
      vmaxps  zmm8, zmm0, zmm8
      vmaxps  zmm9, zmm0, zmm9
      vmaxps  zmm14, zmm0, zmm14
      vmaxps  zmm15, zmm0, zmm15
      vmaxps  zmm16, zmm0, zmm16
      vmaxps  zmm17, zmm0, zmm17
      vmaxps  zmm18, zmm0, zmm18
      vmaxps  zmm19, zmm0, zmm19
      vmaxps  zmm20, zmm0, zmm20
      vmaxps  zmm21, zmm0, zmm21
      vmaxps  zmm22, zmm0, zmm22
      vmaxps  zmm23, zmm0, zmm23
      vmaxps  zmm24, zmm0, zmm24
      vmaxps  zmm25, zmm0, zmm25
      vmaxps  zmm26, zmm0, zmm26
      vmaxps  zmm27, zmm0, zmm27
      vmaxps  zmm28, zmm0, zmm28
      vmaxps  zmm29, zmm0, zmm29
      vmaxps  zmm30, zmm0, zmm30

      # Pop output pointers from the stack.
      mov rcx, [rsp + 8]
      mov rax, [rsp + 24]
      mov r15, [rsp + 40]
      mov r14, [rsp + 56]
      mov r12, [rsp + 72]
      mov r10, [rsp + 88]
      mov r13, [rsp + 104]
      mov rbx, [rsp + 120]
      mov rbp, [rsp + 136]
      mov r8, [rsp + 152]

      # Check whether full or partial store.
      cmp rsi, 32
      jl tail

      vmovups  [rcx], zmm7
      vmovups  [rcx + 64], zmm21
      vmovups  [rax], zmm8
      vmovups  [rax + 64], zmm22
      vmovups  [r15], zmm9
      vmovups  [r15 + 64], zmm23
      vmovups  [r14], zmm14
      vmovups  [r14 + 64], zmm24
      vmovups  [r12], zmm15
      vmovups  [r12 + 64], zmm25
      vmovups  [r10], zmm16
      vmovups  [r10 + 64], zmm26
      vmovups  [r13], zmm17
      vmovups  [r13 + 64], zmm27
      vmovups  [rbx], zmm18
      vmovups  [rbx + 64], zmm28
      vmovups  [rbp], zmm19
      vmovups  [rbp + 64], zmm29
      vmovups  [r8], zmm20
      vmovups  [r8 + 64], zmm30
      add rcx, 128
      add rax, 128
      add r15, 128
      add r14, 128
      add r12, 128
      add r10, 128
      add r13, 128
      add rbx, 128
      add rbp, 128
      add r8, 128

      # Write output pointers to the stack.
      mov [rsp + 8], rcx
      mov [rsp + 24], rax
      mov [rsp + 40], r15
      mov [rsp + 56], r14
      mov [rsp + 72], r12
      mov [rsp + 88], r10
      mov [rsp + 104], r13
      mov [rsp + 120], rbx
      mov [rsp + 136], rbp
      mov [rsp + 152], r8

      sub rsi, 32
      jne outer_loop
      jmp return

tail:
      mov r11, -1
      shlx r11, r11, rsi
      not r11
      kmovw k1, r11d
      shr r11d, 16
      kmovw k2, r11d
      vmovups  ZMMWORD PTR [rcx]{k1}, zmm7
      vmovups  ZMMWORD PTR [rcx + 64]{k2}, zmm21
      vmovups  ZMMWORD PTR [rax]{k1}, zmm8
      vmovups  ZMMWORD PTR [rax + 64]{k2}, zmm22
      vmovups  ZMMWORD PTR [r15]{k1}, zmm9
      vmovups  ZMMWORD PTR [r15 + 64]{k2}, zmm23
      vmovups  ZMMWORD PTR [r14]{k1}, zmm14
      vmovups  ZMMWORD PTR [r14 + 64]{k2}, zmm24
      vmovups  ZMMWORD PTR [r12]{k1}, zmm15
      vmovups  ZMMWORD PTR [r12 + 64]{k2}, zmm25
      vmovups  ZMMWORD PTR [r10]{k1}, zmm16
      vmovups  ZMMWORD PTR [r10 + 64]{k2}, zmm26
      vmovups  ZMMWORD PTR [r13]{k1}, zmm17
      vmovups  ZMMWORD PTR [r13 + 64]{k2}, zmm27
      vmovups  ZMMWORD PTR [rbx]{k1}, zmm18
      vmovups  ZMMWORD PTR [rbx + 64]{k2}, zmm28
      vmovups  ZMMWORD PTR [rbp]{k1}, zmm19
      vmovups  ZMMWORD PTR [rbp + 64]{k2}, zmm29
      vmovups  ZMMWORD PTR [r8]{k1}, zmm20
      vmovups  ZMMWORD PTR [r8 + 64]{k2}, zmm30

return:
      add rsp, 192

      # Restore the callee saved registers.
      pop r12
      pop r13
      pop r14
      pop r15
      pop rbp
      pop rbx
      ret
END_FUNCTION xnn_f32_gemm_minmax_ukernel_10x32__asm_amd64_avx512f_broadcast