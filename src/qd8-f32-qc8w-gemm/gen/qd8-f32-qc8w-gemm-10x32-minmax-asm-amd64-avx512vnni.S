// Copyright 2025 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include "xnnpack/assembly.h"

BEGIN_FUNCTION xnn_qd8_f32_qc8w_gemm_minmax_ukernel_10x32c4__asm_amd64_avx512vnni

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

      add rdx, 3
      and rdx, -4

      # Allocate some space on the stack.
      sub rsp, 1104
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

      # Load quantization params pointer from stack
      mov r11, [rsp + 1192]
      mov edi, [r11 + 0]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 464], zmm6
      mov edi, [r11 + 8]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 528], zmm6
      mov edi, [r11 + 16]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 592], zmm6
      mov edi, [r11 + 24]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 656], zmm6
      mov edi, [r11 + 32]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 720], zmm6
      mov edi, [r11 + 40]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 784], zmm6
      mov edi, [r11 + 48]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 848], zmm6
      mov edi, [r11 + 56]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 912], zmm6
      mov edi, [r11 + 64]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 976], zmm6
      mov edi, [r11 + 72]
      vpbroadcastd zmm6, edi
      vmovups zmmword ptr [rsp + 1040], zmm6

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

      # Initialize accumulators with k_sum * input zero point.
      vmovaps  zmm6, [r9 + 0]
      vmovaps  zmm7, [r9 + 64]
      vpmulld zmm5, zmm6, ZMMWORD PTR [rsp + 464]
      vpmulld zmm12, zmm6, ZMMWORD PTR [rsp + 528]
      vpmulld zmm14, zmm6, ZMMWORD PTR [rsp + 592]
      vpmulld zmm15, zmm6, ZMMWORD PTR [rsp + 656]
      vpmulld zmm16, zmm6, ZMMWORD PTR [rsp + 720]
      vpmulld zmm17, zmm6, ZMMWORD PTR [rsp + 784]
      vpmulld zmm18, zmm6, ZMMWORD PTR [rsp + 848]
      vpmulld zmm19, zmm6, ZMMWORD PTR [rsp + 912]
      vpmulld zmm20, zmm6, ZMMWORD PTR [rsp + 976]
      vpmulld zmm21, zmm6, ZMMWORD PTR [rsp + 1040]
      vpmulld zmm22, zmm7, ZMMWORD PTR [rsp + 464]
      vpmulld zmm23, zmm7, ZMMWORD PTR [rsp + 528]
      vpmulld zmm24, zmm7, ZMMWORD PTR [rsp + 592]
      vpmulld zmm25, zmm7, ZMMWORD PTR [rsp + 656]
      vpmulld zmm26, zmm7, ZMMWORD PTR [rsp + 720]
      vpmulld zmm27, zmm7, ZMMWORD PTR [rsp + 784]
      vpmulld zmm28, zmm7, ZMMWORD PTR [rsp + 848]
      vpmulld zmm29, zmm7, ZMMWORD PTR [rsp + 912]
      vpmulld zmm30, zmm7, ZMMWORD PTR [rsp + 976]
      vpmulld zmm4, zmm7, ZMMWORD PTR [rsp + 1040]
      add r9, 128

inner_loop:
      vmovaps  zmm6, [r9 + 0]
      vmovaps  zmm7, [r9 + 64]
      add r9, 128
      vpbroadcastd zmm2, [rcx + r11]
      vpdpbusd  zmm5, zmm2, zmm6
      vpdpbusd  zmm22, zmm2, zmm7
      vpbroadcastd zmm2, [rax + r11]
      vpdpbusd  zmm12, zmm2, zmm6
      vpdpbusd  zmm23, zmm2, zmm7
      vpbroadcastd zmm2, [r15 + r11]
      vpdpbusd  zmm14, zmm2, zmm6
      vpdpbusd  zmm24, zmm2, zmm7
      vpbroadcastd zmm2, [r14 + r11]
      vpdpbusd  zmm15, zmm2, zmm6
      vpdpbusd  zmm25, zmm2, zmm7
      vpbroadcastd zmm2, [r12 + r11]
      vpdpbusd  zmm16, zmm2, zmm6
      vpdpbusd  zmm26, zmm2, zmm7
      vpbroadcastd zmm2, [r10 + r11]
      vpdpbusd  zmm17, zmm2, zmm6
      vpdpbusd  zmm27, zmm2, zmm7
      vpbroadcastd zmm2, [r13 + r11]
      vpdpbusd  zmm18, zmm2, zmm6
      vpdpbusd  zmm28, zmm2, zmm7
      vpbroadcastd zmm2, [rbx + r11]
      vpdpbusd  zmm19, zmm2, zmm6
      vpdpbusd  zmm29, zmm2, zmm7
      vpbroadcastd zmm2, [rbp + r11]
      vpdpbusd  zmm20, zmm2, zmm6
      vpdpbusd  zmm30, zmm2, zmm7
      vpbroadcastd zmm2, [r8 + r11]
      vpdpbusd  zmm21, zmm2, zmm6
      vpdpbusd  zmm4, zmm2, zmm7

      add r11, 4
      cmp rdx, r11
      jne inner_loop
inner_loop_end:

      # Convert from int32 to float.
      vcvtdq2ps zmm5, zmm5
      vcvtdq2ps zmm12, zmm12
      vcvtdq2ps zmm14, zmm14
      vcvtdq2ps zmm15, zmm15
      vcvtdq2ps zmm16, zmm16
      vcvtdq2ps zmm17, zmm17
      vcvtdq2ps zmm18, zmm18
      vcvtdq2ps zmm19, zmm19
      vcvtdq2ps zmm20, zmm20
      vcvtdq2ps zmm21, zmm21
      vcvtdq2ps zmm22, zmm22
      vcvtdq2ps zmm23, zmm23
      vcvtdq2ps zmm24, zmm24
      vcvtdq2ps zmm25, zmm25
      vcvtdq2ps zmm26, zmm26
      vcvtdq2ps zmm27, zmm27
      vcvtdq2ps zmm28, zmm28
      vcvtdq2ps zmm29, zmm29
      vcvtdq2ps zmm30, zmm30
      vcvtdq2ps zmm4, zmm4
      # Load quantization_params pointer from stack
      mov r11, [rsp + 1192]
      vmulps zmm5, zmm5, DWORD PTR [r11 + 4]{1to16}
      vmulps zmm12, zmm12, DWORD PTR [r11 + 12]{1to16}
      vmulps zmm14, zmm14, DWORD PTR [r11 + 20]{1to16}
      vmulps zmm15, zmm15, DWORD PTR [r11 + 28]{1to16}
      vmulps zmm16, zmm16, DWORD PTR [r11 + 36]{1to16}
      vmulps zmm17, zmm17, DWORD PTR [r11 + 44]{1to16}
      vmulps zmm18, zmm18, DWORD PTR [r11 + 52]{1to16}
      vmulps zmm19, zmm19, DWORD PTR [r11 + 60]{1to16}
      vmulps zmm20, zmm20, DWORD PTR [r11 + 68]{1to16}
      vmulps zmm21, zmm21, DWORD PTR [r11 + 76]{1to16}
      vmulps zmm22, zmm22, DWORD PTR [r11 + 4]{1to16}
      vmulps zmm23, zmm23, DWORD PTR [r11 + 12]{1to16}
      vmulps zmm24, zmm24, DWORD PTR [r11 + 20]{1to16}
      vmulps zmm25, zmm25, DWORD PTR [r11 + 28]{1to16}
      vmulps zmm26, zmm26, DWORD PTR [r11 + 36]{1to16}
      vmulps zmm27, zmm27, DWORD PTR [r11 + 44]{1to16}
      vmulps zmm28, zmm28, DWORD PTR [r11 + 52]{1to16}
      vmulps zmm29, zmm29, DWORD PTR [r11 + 60]{1to16}
      vmulps zmm30, zmm30, DWORD PTR [r11 + 68]{1to16}
      vmulps zmm4, zmm4, DWORD PTR [r11 + 76]{1to16}
      vmovaps zmm10, [r9 + 0]
      vmovaps zmm11, [r9 + 64]
      add r9, 128
      vmovaps zmm6, [r9 + 0]
      vmovaps zmm7, [r9 + 64]
      add r9, 128
      vfmadd213ps zmm5, zmm10, zmm6
      vfmadd213ps zmm12, zmm10, zmm6
      vfmadd213ps zmm14, zmm10, zmm6
      vfmadd213ps zmm15, zmm10, zmm6
      vfmadd213ps zmm16, zmm10, zmm6
      vfmadd213ps zmm17, zmm10, zmm6
      vfmadd213ps zmm18, zmm10, zmm6
      vfmadd213ps zmm19, zmm10, zmm6
      vfmadd213ps zmm20, zmm10, zmm6
      vfmadd213ps zmm21, zmm10, zmm6
      vfmadd213ps zmm22, zmm11, zmm7
      vfmadd213ps zmm23, zmm11, zmm7
      vfmadd213ps zmm24, zmm11, zmm7
      vfmadd213ps zmm25, zmm11, zmm7
      vfmadd213ps zmm26, zmm11, zmm7
      vfmadd213ps zmm27, zmm11, zmm7
      vfmadd213ps zmm28, zmm11, zmm7
      vfmadd213ps zmm29, zmm11, zmm7
      vfmadd213ps zmm30, zmm11, zmm7
      vfmadd213ps zmm4, zmm11, zmm7
      # Min/max clamping.
      vminps  zmm5, zmm1, zmm5
      vminps  zmm12, zmm1, zmm12
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
      vminps  zmm4, zmm1, zmm4
      vmaxps  zmm5, zmm0, zmm5
      vmaxps  zmm12, zmm0, zmm12
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
      vmaxps  zmm4, zmm0, zmm4

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

      vmovups  [rcx], zmm5
      vmovups  [rcx + 64], zmm22
      vmovups  [rax], zmm12
      vmovups  [rax + 64], zmm23
      vmovups  [r15], zmm14
      vmovups  [r15 + 64], zmm24
      vmovups  [r14], zmm15
      vmovups  [r14 + 64], zmm25
      vmovups  [r12], zmm16
      vmovups  [r12 + 64], zmm26
      vmovups  [r10], zmm17
      vmovups  [r10 + 64], zmm27
      vmovups  [r13], zmm18
      vmovups  [r13 + 64], zmm28
      vmovups  [rbx], zmm19
      vmovups  [rbx + 64], zmm29
      vmovups  [rbp], zmm20
      vmovups  [rbp + 64], zmm30
      vmovups  [r8], zmm21
      vmovups  [r8 + 64], zmm4
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
      vmovups  ZMMWORD PTR [rcx]{k1}, zmm5
      vmovups  ZMMWORD PTR [rcx + 64]{k2}, zmm22
      vmovups  ZMMWORD PTR [rax]{k1}, zmm12
      vmovups  ZMMWORD PTR [rax + 64]{k2}, zmm23
      vmovups  ZMMWORD PTR [r15]{k1}, zmm14
      vmovups  ZMMWORD PTR [r15 + 64]{k2}, zmm24
      vmovups  ZMMWORD PTR [r14]{k1}, zmm15
      vmovups  ZMMWORD PTR [r14 + 64]{k2}, zmm25
      vmovups  ZMMWORD PTR [r12]{k1}, zmm16
      vmovups  ZMMWORD PTR [r12 + 64]{k2}, zmm26
      vmovups  ZMMWORD PTR [r10]{k1}, zmm17
      vmovups  ZMMWORD PTR [r10 + 64]{k2}, zmm27
      vmovups  ZMMWORD PTR [r13]{k1}, zmm18
      vmovups  ZMMWORD PTR [r13 + 64]{k2}, zmm28
      vmovups  ZMMWORD PTR [rbx]{k1}, zmm19
      vmovups  ZMMWORD PTR [rbx + 64]{k2}, zmm29
      vmovups  ZMMWORD PTR [rbp]{k1}, zmm20
      vmovups  ZMMWORD PTR [rbp + 64]{k2}, zmm30
      vmovups  ZMMWORD PTR [r8]{k1}, zmm21
      vmovups  ZMMWORD PTR [r8 + 64]{k2}, zmm4

return:
      add rsp, 1104

      # Restore the callee saved registers.
      pop r12
      pop r13
      pop r14
      pop r15
      pop rbp
      pop rbx
      ret
END_FUNCTION xnn_qd8_f32_qc8w_gemm_minmax_ukernel_10x32c4__asm_amd64_avx512vnni