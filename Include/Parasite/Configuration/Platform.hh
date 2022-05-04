//  Parasite::Configuration
//  Copyright 2022 DeathBlizzard
//  
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
//  conditions are met:
//  
//  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//      disclaimer.
//  
//  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials provided with the distribution.
//  
//  3.  Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef PARASITE_ENGINE_CONFIGURATION__PLATFORM_HH_
#define PARASITE_ENGINE_CONFIGURATION__PLATFORM_HH_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file       Parasite/Configuration/Platform.hh
/// Platform, Compiler, Architecture Identification and Conditional Compilation Macros
/// @details    This file contains Platform, Compiler and architecture identification along with conditional compilation macros.
///             These macros are often used by other Parasite modules for building cross platform / compiler / architecture
///             packagaes and/or executables.
///
///             The following are the list of platforms that are supported by
///             Parasite:
///                 1.  Microsoft Windows
///                 2.  Linux
///                 3.  UNIX (FreeBSD, OpenBSD, NetBSD, etc.)
///                 4.  Androidd
///                 5.  Apple Mac
///
///             The follwing are the list of compilers that are recognised and
///             supported by Parasite:
///                 1.  LLVM Clang
///                 2.  Apple Clang
///                 3.  GNU C / C++ Compiler Toolchain
///                 4.  Microsoft Visual C++
///                 5.  Intel oneAPI C / C++ / DPC++ Compiler
///                 6.  Nvidia CUDA C++ Compiler
///
///             The follwing are the architectures that are recognised and
///             supported by Parasite:
///                 1.  x86
///                 2.  x86_64
///                 3.  ARM
///
///             The follwing are the SIMD capabilities that are recognised and
///             supported by Parasite:
///                 1.  SSE
///                 2.  SSE 2
///                 3.  SSE 3
///                 4.  SSSE 3
///                 5.  SSE 4.1
///                 6.  SSE 4.2
///                 7.  AVX
///                 8.  AVX2
///                 9.  NEON
/// @note       This file is not supposed to be directly included in the client source. In order to include this header file,
///             please include @c Parasite/Configuration.hh
/// @addtogroup parasite_configuration
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @defgroup   parasite_platform_identification    Parasite::Configuration Platform Identification
///     @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  ----    Compiler Identification                                                                                 BEGIN   ----

/// Parasite Unknown Compiler
#define PARASITE_COMPILER_UNKNOWN       0x00
/// Parasite LLVM Clang Compiler
#define PARASITE_COMPILER_LLVM_CLANG    0x01
/// Parasite Apple Clang Compiler
#define PARASITE_COMPILER_APPLE_CLANG   0x02
/// Parasite GNU C Compiler
#define PARASITE_COMPILER_GCC           0x04
/// Parasite Microsoft Visual C++ Compiler
#define PARASITE_COMPILER_MSVC          0x08
/// Parasite Intel C/C++ Compiler
#define PARASITE_COMPILER_INTEL         0x10
/// Parasite Nvidia CUDA C++ Compiler
#define PARASITE_COMPILER_NVCC          0x20

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parasite::Configuration Compiler
/// @details    This macro expands to one of the `PARASITE_COMPILER_*` definitions depending on the host platform's compiler
///             that is used to compile sources including this header file. This macro is primarily used to define compiler
///             specific definitions and conditional compilation macros. The host compiler that is used to compile the
///             Parasite::Configuration package. The following are the supported compilers:
///                 -#  LLVM Clang
///                 -#  Apple Clang
///                 -#  GNU C Compiler Toolchain
///                 -#  Microsoft Visual C++
///                 -#  Nvidia CUDA C++ Compiler for GPU
///                 -#  Intel C/C++ Compiler
/// @note       This macro expands to a bitfield representing the host platform compiler. In order to retrieve the compiler name
///             utilize @ref PARASITE_COMPILER_NAME
/// @see        PARASITE_COMPILER_NAME
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_COMPILER
#    if defined(PARASITE_FORCE_UNKNOWN_COMPILER)
#        define PARASITE_COMPILER PARASITE_COMPILER_UNKNOWN
#    elif defined(__clang__)
#        if defined(__apple_build_version__)
#            define PARASITE_COMPILER PARASITE_COMPILER_APPLE_CLANG
#        else
#            define PARASITE_COMPILER PARASITE_COMPILER_LLVM_CLANG
#        endif
#    elif defined(__GNUC__)
#        define PARASITE_COMPILER PARASITE_COMPILER_GCC
#    elif defind(_MSC_VER)
#        define PARASITE_COMPILER PARASITE_COMPILER_MSVC
#    elif defined(__INTEL_COMPILER)
#        define PARASITE_COMPILER PARASITE_COMPILER_INTEL
#    elif defined(__CUDACC__)
#        define PARASITE_COMPILER PARASITE_COMPILER_CUDA
#    else
#        define PARASITE_COMPILER PARASITE_COMPILER_UNKNOWN
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parasite Host Platform Compiler Name
/// @details    This macro expands to a string (const char *) representing the name of the compiler used to compile source file
///             including this header.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_COMPILER_NAME
#    if PARASITE_COMPILER & PARASITE_COMPILER_LLVM_CLANG
#        define PARASITE_COMPILER_NAME "LLVM Clang"
#    elif PARASITE_COMPILER & PARASITE_COMPILER_APPLE_CLANG
#        define PARASITE_COMPILER_NAME "Apple Clang"
#    elif PARASITE_COMPILER & PARASITE_COMPILER_GCC
#        define PARASITE_COMPILER_NAME "GNU C Compiler Toolchain"
#    elif PARASITE_COMPILER & PARASITE_COMPILER_MSVC
#        define PARASITE_COMPILER_NAME "Microsoft Visual C/C++"
#    elif PARASITE_COMPILER & PARASITE_COMPILER_INTEL
#        define PARASITE_COMPILER_NAME "Intel C++ Compiler"
#    elif PARASITE_COMPILER & PARASITE_COMPILER_CUDA
#        define PARASITE_COMPILER_NAME "Nvidia CUDA C++ Compiler"
#    else
#        define PARASITE_COMPILER_NAME "Unknown"
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parasite Host Platform Compiler Version
/// @details    This macro expands to the numerical representation of the compiler version. The version scheme is different for
///             different compilers and cannot be used reliably for version identification
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_COMPILER_VERSION
#    if PARASITE_COMPILER & (PARASITE_COMPILER_LLVM_CLANG | PARASITE_COMPILER_APPLE_CLANG)
#        define PARASITE_COMPILER_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#    elif PARASITE_COMPILER & PARASITE_COMPILER_GCC
#        define PARASITE_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#    elif PARASITE_COMPILER & PARASITE_COMPILER_MSVC
#        define PARASITE_COMPILER_VERSION _MSC_FULL_VER
#    elif PARASITE_COMPILER & PARASITE_COMPILER_INTEL
#        define PARASITE_COMPILER_VERSION __INTEL_COMPILER
#    elif PARASITE_COMPILER & PARASITE_COMPILER_CUDA
#        define PARASITE_COMPILER_VERSION CUDA_VERSION
#    else
#        define PARASITE_COMPILER_VERSION 0
#    endif
#endif

//  ----    Compiler Identification                                                                                 END     ----
//  ----    Platform Identification                                                                                 BEGIN   ----

/// Parasite Unknown platform
#define PARASITE_PLATFORM_UNKNOWN   0x00
/// Parasite Microsoft Windows platform
#define PARASITE_PLATFORM_WINDOWS   0x01
/// Parasite Cygwin (under Microsoft Windows) platform
#define PARASITE_PLATFORM_CYGWIN    0x02
/// Parasite Linux platform
#define PARASITE_PLATFORM_LINUX     0x04
/// Parasite UNIXs other than Linux platform
#define PARASITE_PLATFORM_UNIX      0x08
/// Parasite Android platform
#define PARASITE_PLATFORM_ANDROID   0x10
/// Parasite Apple MacOS platform
#define PARASITE_PLATFORM_MACOS     0x20

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parasite::Configuration Platform
/// @details    The host platform that was used to compile Parasite::Configuration.
///             The following are the supported platforms
///                 -#  Microsoft Windows
///                 -#  Cygwin under Microsoft Windows
///                 -#  Linux kernel
///                 -#  Android
///                 -#  Apple MacOS
///                 -#  Other *Nix
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_PLATFORM
#    if defined(PARASITE_FORCE_UNKNOWN_PLATFORM)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_UNKNOWN
#    elif defined(__CYGWIN__)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_CYGWIN
#    elif defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_WINDOWS
#    elif defined(__ANDROID__)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_ANDROID
#    elif defined(__linux) || defined(linux) || defined(__linux__)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_LINUX
#    elif defined(__unix) || defined(__unix__)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_UNIX
#    elif defined(__APPLE__)
#        define PARASITE_PLATFORM PARASITE_PLATFORM_APPLE
#    else
#        define PARASITE_PLATFORM PARASITE_PLATFORM_UNKNOWN
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parasite::Configuration Platform Name
/// @details    This macro expands to a string (const char *) which represents the formal name of the operating system according to
///             Parasite::Configuration Module
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_PLATFORM_NAME
#    if PARASITE_PLATFORM & PARASITE_PLATFORM_WINDOWS
#        define PARASITE_PLATFORM_NAME "Microsoft Windows"
#    elif PARASITE_PLATFORM & PARASITE_PLATFORM_CYGWIN
#        define PARASITE_PLATFORM_NAME "Microsoft Windows under Cygwin"
#    elif PARASITE_PLATFORM & PARASITE_PLATFORM_LINUX
#        define PARASITE_PLATFORM_NAME "Linux"
#    elif PARASITE_PLATFORM & PARASITE_PLATFORM_UNIX
#        define PARASITE_PLATFORM_NAME "UNIX"
#    elif PARASITE_PLATFORM & PARASITE_PLATFORM_ANDROID
#        define PARASITE_PLATFORM_NAME "Android"
#    elif PARASITE_PLATFORM & PARASITE_PLATFORM_APPLE
#        define PARASITE_PLATFORM_NAME "Apple"
#    else
#        define PARASITE_PLATFORM_NAME "Unknown"
#    endif
#endif

/// 32 bit Architecture / Execution model
#define PARASITE_BUILD_MODEL_32 0x01
/// 64 bit Architecture / Execution model
#define PARASITE_BUILD_MODEL_64 0x02

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Execution model of the target platform
/// @details    This macro is a conditional compilation flag that identifies both 32 bit and 64 bit execution models.
///             This macro currently recognizes X86 and ARM processor models
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_BUILD_MODEL
#    if defined(_M_ARM64) || defined(__LP64__) || defined(_M_X64) || defined(__ppc64__) || defined(__x86_64__)
#        define PARASITE_BUILD_MODEL PARASITE_BUILD_MODEL_64
#    elif defined(__i386__) || defined(__ppc__) || defined(__ILP32__) || defined(_M_ARM)
#        define PARASITE_BUILD_MODEL PARASITE_BUILD_MODEL_32
#    else
#        define PARASITE_BUILD_MODEL PARASITE_BUILD_MODEL_32
#    endif
#endif

//  ----    Platform Identification                                                                                 END     ----
//  ----    Platform SIMD Intrinsics Support Detection                                                              BEGIN   ----

/// Bit representing the x86 Architecture
#define PARASITE_ARCHITECTURE_BIT_X86       0x0001
/// Bit representing the x86 SSE SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_SSE       0x0002
/// Bit representing the x86 SSE 2 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_SSE2      0x0004
/// Bit representing the x86 SSE 3 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_SSE3      0x0010
/// Bit representing the x86 SSSE 3 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_SSSE3     0x0020
/// Bit representing the x86 SSE 4.1 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_SSE41     0x0040
/// Bit representing the x86 SSE 4.2 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_SSE42     0x0080
/// Bit representing the x86 AVX SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_AVX       0x0100
/// Bit representing the x86 AVX2 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_AVX2      0x0200
/// Bit representing the ARM Architecture
#define PARASITE_ARCHITECTURE_BIT_ARM       0x0400
/// Bit representing the ARM Neon SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_NEON      0x0800
/// Bit representing the ARM V8 SIMD Intrinsics
#define PARASITE_ARCHITECTURE_BIT_ARMV8     0x1000

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Unknown Architecture
/// @details    Parasite Engine is capable of compiling the entire codebase without relying on SIMD intrinsics. This can be
///             achieved by defining `PARASITE_FORCE_UNKNOWN_ARCHITECTURE` allowing the depending module to disable all SIMD
///             optimizations. This macro is, by default, not defined as a compilation flag.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_UNKNOWN 0x0000
/// x86 Architecture
#define PARASITE_ARCHITECTURE_X86 PARASITE_ARCHITECTURE_BIT_X86
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - SSE SIMD
/// @details    Streaming SIMD Extensions (SSE) is a Single Instruction, Multiple Data (SIMD) instruction set extension to the
///             x86 architecture. These instructions contain nearly 70 instructions which are mostly designed to operate on
///             single precision floating point data. A set of 70 new instructions were added under the SSE bracket.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_SSE PARASITE_ARCHITECTURE_X86 | PARASITE_ARCHITECTURE_BIT_SSE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - SSE2 SIMD
/// @details    Streaming SIMD Extensions 2 (SSE2) is one of the Intel Single Instruction, Multiple Data (SIMD) processor
///             supplementary instruction sets first introduced by Intel with the initial version of the Pentium 4 in 2000.
///             It extends the earlier SSE instruction set, and is intended to fully replace MMX. In total 144 new instructions
///             were expanded beyond SSE.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_SSE2 PARASITE_ARCHITECTURE_SSE | PARASITE_ARCHITECTURE_BIT_SSE2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - SSE3 SIMD
/// @details    Streaming SIMD Extensions 3 (SSE3), also known by its Intel code name Prescott New Instructions (PNI), is the
///             third iteration of the SSE instruction set for the IA-32 (x86) architecture. Intel introduced SSE3 in early
///             2004 with the Prescott revision of their Pentium 4 CPU. SSE3 contains 13 new instructions over SSE2.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_SSE3 PARASITE_ARCHITECTURE_SSE2 | PARASITE_ARCHITECTURE_BIT_SSE3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - SSSE3 SIMD
/// @details    Supplemental Streaming SIMD Extensions 3 (SSSE3 or SSE3S) is a SIMD instruction set created by Intel and
///             is the fourth iteration of the SSE technology. It was first introduced with Intel processors based on the
///             Core microarchitecture on June 26, 2006 with the "Woodcrest" Xeons. contains 16 new discrete instructions.
///             Each instruction can act on 64-bit MMX or 128-bit XMM registers. Therefore, Intel's materials refer to
///             32 new instructions.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_SSSE3 PARASITE_ARCHITECTURE_SSE3 | PARASITE_ARCHITECTURE_BIT_SSSE3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - SSE4.1 SIMD
/// @details    SSE4 (Streaming SIMD Extensions 4) is a SIMD CPU instruction set used in the Intel Core microarchitecture
///             and AMD K10 (K8L). Intel SSE4 consists of 54 instructions. A subset consisting of 47 instructions, referred
///             to as SSE4.1 in some Intel documentation, is available in Penryn
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_SSE41 PARASITE_ARCHITECTURE_SSSE3 | PARASITE_ARCHITECTURE_BIT_SSE41
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - SSE4.2 SIMD
/// @details    SSE4 (Streaming SIMD Extensions 4) is a SIMD CPU instruction set used in the Intel Core microarchitecture
///             and AMD K10 (K8L). Intel SSE4 consists of 54 instructions. A subset consisting of 7 remaining instructions,
////            in addition to ones from SSE4.1, is first available in Nehalem-based Core i7. Intel credits feedback from
///             developers as playing an important role in the development of the instruction set.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_SSE42 PARASITE_ARCHITECTURE_SSE41 | PARASITE_ARCHITECTURE_BIT_SSE42
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - AVX SIMD
/// @details    Advanced Vector Extensions (AVX) are extensions to the x86 instruction set architecture for microprocessors
///             from Intel and Advanced Micro Devices (AMD). They were proposed by Intel in March 2008 and first supported
///             by Intel with the Sandy Bridge processor shipping in Q1 2011 and later by AMD with the Bulldozer processor
///             shipping in Q3 2011.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_AVX PARASITE_ARCHITECTURE_SSE42 | PARASITE_ARCHITECTURE_BIT_AVX
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      x86 - AVX2 SIMD
/// @details    Advanced Vector Extensions (AVX) are extensions to the x86 instruction set architecture for microprocessors
///             from Intel and Advanced Micro Devices (AMD). AVX2 (also known as Haswell New Instructions) expands most integer
///             commands to 256 bits and introduces new instructions. They were first supported by Intel with the Haswell
///             processor, which shipped in 2013.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ARCHITECTURE_AVX2 PARASITE_ARCHITECTURE_AVX | PARASITE_ARCHITECTURE_BIT_AVX2
/// ARM Architecture
#define PARASITE_ARCHITECTURE_ARM PARASITE_ARCHITECTURE_BIT_ARM
/// ARM + ARM Neon
#define PARASITE_ARCHITECTURE_NEON PARASITE_ARCHITECTURE_ARM | PARASITE_ARCHITECTURE_BIT_NEON
/// ARM Neon + ARMV8 Intrinsics
#define PARASITE_ARCHITECTURE_ARMV8 PARASITE_ARCHITECTURE_NEON | PARASITE_ARCHITECTURE_BIT_ARMV8

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Parasite::Configuration Architecture
/// @details    The host platform architecture along with SIMD (Single Instruction Multiple Data) Intrinsics that were enabled
///             and expected to be supported by the target system. The following are the supported architectures and SIMD
///             Intrinsics
///             -#  @ref PARASITE_ARCHITECTURE_X86      "x86 Architecture"
///             -#  @ref PARASITE_ARCHITECTURE_SSE      "x86 Architecture  (with SSE)"
///             -#  @ref PARASITE_ARCHITECTURE_SSE2     "x86 Architecture  (with SSE, SSE 2)"
///             -#  @ref PARASITE_ARCHITECTURE_SSE3     "x86 Architecture  (with SSE, SSE 2, SSE 3)"
///             -#  @ref PARASITE_ARCHITECTURE_SSSE3    "x86 Architecture  (with SSE, SSE 2, SSE 3, SSSE 3)"
///             -#  @ref PARASITE_ARCHITECTURE_SSE41    "x86 Architecture  (with SSE, SSE 2, SSE 3, SSSE 3, SSE 4.1)"
///             -#  @ref PARASITE_ARCHITECTURE_SSE42    "x86 Architecture  (with SSE, SSE 2, SSE 3, SSSE 3, SSE 4.1, SSE 4.2)"
///             -#  @ref PARASITE_ARCHITECTURE_AVX      "x86 Architecture  (with SSE - SSE 4.2, AVX)"
///             -#  @ref PARASITE_ARCHITECTURE_AVX2     "x86 Architecture  (with SSE - SSE 4.2, AVX2)"
///             -#  @ref PARASITE_ARCHITECTURE_ARM      "ARM Architecture"
///             -#  @ref PARASITE_ARCHITECTURE_NEON     "ARM Architecture (with ARM Neon)"
///             -#  @ref PARASITE_ARCHITECTURE_ARMV8    "ARM Architecture (with ARM Neon, ARM V8 Intrinsics)"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARASITE_ARCHITECTURE
#    if defined(PARASITE_FORCE_UNKNOWN_ARCHITECTURE) || defined(PARASITE_NO_SIMD_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_UNKNOWN
#    elif defined(PARASITE_FORCE_AVX2_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_AVX2
#    elif defined(PARASITE_FORCE_AVX_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_AVX
#    elif defined(PARASITE_FORCE_SSE42_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE42
#    elif defined(PARASITE_FORCE_SSE41_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE41
#    elif defined(PARASITE_FORCE_SSSE3_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSSE3
#    elif defined(PARASITE_FORCE_SSE3_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE3
#    elif defined(PARASITE_FORCE_SSE2_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE2
#    elif defined(PARASITE_FORCE_SSE_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE
#    elif defined(PARASITE_FORCE_X86_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_X86
#    elif defined(PARASITE_FORCE_ARMV8_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_ARMV8
#    elif defined(PARASITE_FORCE_NEON_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_NEON
#    elif defined(PARASITE_FORCE_ARM_INTRINSICS)
#        define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_ARM
#    elif defined(PARASITE_FORCE_INTRINSICS)
#        if defined(__AVX2__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_AVX2
#        elif defined(__AVX__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_AVX
#        elif defined(__SSE4_2__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE42
#        elif defined(__SSE4_1__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE41
#        elif defined(__SSSE3__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSSE3
#        elif defined(__SSE3__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE3
#        elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86_FP)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_SSE2
#        elif defined(__i386__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_X86
#        elif defined(__ARM_ARCH) && (__ARM_ARCH >= 8)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_ARMV8
#        elif defined(__ARM_NEON)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_NEON
#        elif defined(__arm__) || defined(_M_ARM)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_ARM
#        else
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_UNKNOWN
#        endif
#    else
#        if defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86) || defined(__i386__)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_X86
#        elif defined(__arm__) || defined(_M_ARM)
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_ARM
#        else
#            define PARASITE_ARCHITECTURE PARASITE_ARCHITECTURE_UNKNOWN
#        endif
#    endif
#endif

//  ----    Platform SIMD Intrinsics Support Detection                                                              END     ----
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///     @}
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif