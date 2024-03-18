![logo](https://github.com/ContingencyOfTautologicalContradictions/Lucy/blob/main/Logo.png)

A modern, C++23 multi-platform general-purpose library, with a focus on safety, performance and completeness.


## Compilers

Lucy supports GCC, MSVC, Apple Clang, and Clang.


## Versioning

Lucy defines various macros for the versioning, which are:

- ``lucy_major``: the major version number
- ``lucy_middle``: the middle version number
- ``lucy_minor``: the minor version number

For example, if the Lucy's version is 3.0.1, these macros would be defined as:

- ``lucy_major``: ``3``
- ``lucy_middle``: ``0``
- ``lucy_minor``: ``1``

The actual version is ``0.0.1``.


## Debug

To enable the debug mode within Lucy, you must define the macro ``lucy_debug``. To build for release (non-debug) mode, don't define anything.

The debug mode will use C++ exceptions (and therefore RTTI) to better notify the Lucy's users about what went wrong.

The release mode will assume exceptions and RTTI are disabled, and abort once an abnormal situation was found.


## Requirements

The supported systems for now are ``macOS (arm64)``, ``iOS (arm64)``, ``Android (arm64)``, ``Linux (arm64, risc-v64, amd64)``, and ``Windows (amd64)``.

The general requirements for any of these supported platforms are:

- 64-bits address space
- Git 2.44+

The following requirements are specific of each system:
  
### For macOS

- Define the macro ``lucy_arm64``
- Define the macro ``lucy_mac``
- Latest macOS (14.4+)
- Latest XCode (15.3+)
- A GPU supporting Metal Shading Language 3.1+

### For iOS

- Define the macro ``lucy_arm64``
- Define the macro ``lucy_ios``
- Latest iOS (17.4+)
- Latest iOS Simulator (17.4+)
- Latest macOS (14.4+)
- Latest XCode (15.3+)
- A GPU supporting Metal Shading Language 3.1+

### For Android

- Define the macro ``lucy_arm64``
- Define the macro ``lucy_android``
- Latest Android NDK (R26+)
- Latest Android SDK (34+)
- Latest Android Studio (3.2.1+)
- Latest Gradle (8.2+)
- A GPU supporting Vulkan 1.3+

### For Linux

- Define the macro ``lucy_arm64``, ``lucy_amd64``, or ``lucy_riscv64``, depending on the architecture you target
- Define the macro ``lucy_linux``
- Latest Linux kernel
- Latest Wayland library (1.21+)
- Latest GCC (14+)
- Latest Vulkan (1.3+)
- A GPU supporting Vulkan 1.3+

### For Windows

- Define the macro ``lucy_amd64``
- Define the macro ``lucy_windows``
- Latest Windows 11+
- Latest Visual Studio 2022 (17.6+)
- Latest Windows 11 Kit (10.0.22621+)
- A GPU supporting the latest D3D12+


## Architecture extensions

### For arm64

- Define the macro ``lucy_neon`` to enable NEON intrinsics
- Define the macro ``lucy_sve`` to enable SVE intrinsics
- Define the macro ``lucy_sve2`` to enable SVE2 intrinsics


### For amd64

- Define the macro ``lucy_sse3`` to enable SSE3 intrinsics
- Define the macro ``lucy_ssse3`` to enable SSSE3 intrinsics
- Define the macro ``lucy_sse4_1`` to enable SSE4.1 intrinsics
- Define the macro ``lucy_sse4_2`` to enable SSE4.2 intrinsics
- Define the macro ``lucy_avx`` to enable AVX intrinsics
- Define the macro ``lucy_f16c`` to enable F16C intrinsics
- Define the macro ``lucy_fma`` to enable FMA intrinsics
- Define the macro ``lucy_avx2`` to enable AVX2 intrinsics
- Define the macro ``lucy_avx_vnni`` to enable AVX VNNI intrinsics
- Define the macro ``lucy_avx_vnni_int8`` to enable AVX VNNI INT8 intrinsics
- Define the macro ``lucy_avx_ne_convert`` to enable AVX NE CONVERT intrinsics
- Define the macro ``lucy_avx_ifma`` to enable AVX IFMA intrinsics
- Define the macro ``lucy_avx_vnni_int16`` to enable AVX VNNI INT16 intrinsics
- Define the macro ``lucy_sha512`` to enable SHA512 intrinsics
- Define the macro ``lucy_sm3`` to enable SM3 intrinsics
- Define the macro ``lucy_sm4`` to enable SM4 intrinsics
- Define the macro ``lucy_avx512_f`` to enable AVX512 F intrinsics
- Define the macro ``lucy_avx512_bw`` to enable AVX512 BW intrinsics
- Define the macro ``lucy_avx512_cd`` to enable AVX512 CD intrinsics
- Define the macro ``lucy_avx512_dq`` to enable AVX512 DQ intrinsics
- Define the macro ``lucy_avx512_ifma52`` to enable AVX512 IFMA52 intrinsics
- Define the macro ``lucy_avx512_vl`` to enable AVX512 VL intrinsics
- Define the macro ``lucy_avx512_vpopcntdq`` to enable AVX512 VPOPCNTDQ intrinsics
- Define the macro ``lucy_avx512_bf16`` to enable AVX512 BF16 intrinsics
- Define the macro ``lucy_avx512_bitalg`` to enable AVX512 BITALG intrinsics
- Define the macro ``lucy_avx512_vbmi`` to enable AVX512 VBMI intrinsics
- Define the macro ``lucy_avx512_vbmi2`` to enable AVX512 VBMI2 intrinsics
- Define the macro ``lucy_avx512_vnni`` to enable AVX512 VNNI intrinsics
- Define the macro ``lucy_avx512_vp2intersect`` to enable AVX512 VP2INTERSECT intrinsics
- Define the macro ``lucy_avx512_fp16`` to enable AVX512 FP16 intrinsics
- Define the macro ``lucy_amx_bf16`` to enable AMX BF16 intrinsics
- Define the macro ``lucy_amx_int8`` to enable AMX INT8 intrinsics
- Define the macro ``lucy_amx_tile`` to enable AMX TILE intrinsics
- Define the macro ``lucy_amx_fp16`` to enable AMX FP16 intrinsics
- Define the macro ``lucy_amx_complex`` to enable AMX COMPLEX intrinsics
- Define the macro ``lucy_svml`` to enable SVML intrinsics
- Define the macro ``lucy_adx`` to enable ADX intrinsics
- Define the macro ``lucy_aes`` to enable AES intrinsics
- Define the macro ``lucy_bmi1`` to enable BMI1 intrinsics
- Define the macro ``lucy_bmi2`` to enable BMI2 intrinsics
- Define the macro ``lucy_cet_ss`` to enable CET SS intrinsics
- Define the macro ``lucy_cldemote`` to enable CLDEMOTE intrinsics
- Define the macro ``lucy_clflushopt`` to enable CLFLUSHOPT intrinsics
- Define the macro ``lucy_clwb`` to enable CLWB intrinsics
- Define the macro ``lucy_cmpccxadd`` to enable CMPCCXADD intrinsics
- Define the macro ``lucy_crc32`` to enable CRC32 intrinsics
- Define the macro ``lucy_enqcmd`` to enable ENQCMD intrinsics
- Define the macro ``lucy_fsgsbase`` to enable FSGSBASE intrinsics
- Define the macro ``lucy_fxsr`` to enable FXSR intrinsics
- Define the macro ``lucy_gfni`` to enable GFNI intrinsics
- Define the macro ``lucy_hreset`` to enable HRESET intrinsics
- Define the macro ``lucy_invpcid`` to enable INVPCID intrinsics
- Define the macro ``lucy_keylocker`` to enable KEYLOCKER intrinsics
- Define the macro ``lucy_keylocker_wide`` to enable KEYLOCKER WIDE intrinsics
- Define the macro ``lucy_lzcnt`` to enable LZCNT intrinsics
- Define the macro ``lucy_monitor`` to enable MONITOR intrinsics
- Define the macro ``lucy_movbe`` to enable MOVBE intrinsics
- Define the macro ``lucy_movdir64b`` to enable MOVDIR64B intrinsics
- Define the macro ``lucy_movdiri`` to enable MOVDIRI intrinsics
- Define the macro ``lucy_mpx`` to enable MPX intrinsics
- Define the macro ``lucy_pclmulqdq`` to enable PCLMULQDQ intrinsics
- Define the macro ``lucy_pconfig`` to enable PCONFIG intrinsics
- Define the macro ``lucy_popcnt`` to enable POPCNT intrinsics
- Define the macro ``lucy_prefetchi`` to enable PREFETCHI intrinsics
- Define the macro ``lucy_prfchw`` to enable PRFCHW intrinsics
- Define the macro ``lucy_rao_int`` to enable RAO INT intrinsics
- Define the macro ``lucy_rdpid`` to enable RDPID intrinsics
- Define the macro ``lucy_rdrand`` to enable RDRAND intrinsics
- Define the macro ``lucy_rdseed`` to enable RDSEED intrinsics
- Define the macro ``lucy_rdtscp`` to enable RDTSCP intrinsics
- Define the macro ``lucy_rtm`` to enable RTM intrinsics
- Define the macro ``lucy_serialize`` to enable SERIALIZE intrinsics
- Define the macro ``lucy_sha`` to enable SHA intrinsics
- Define the macro ``lucy_tsc`` to enable TSC intrinsics
- Define the macro ``lucy_tsxldtrk`` to enable TSXLDTRK intrinsics
- Define the macro ``lucy_uintr`` to enable UINTR intrinsics
- Define the macro ``lucy_vaes`` to enable VAES intrinsics
- Define the macro ``lucy_vpclmulqdq`` to enable VPCLMULQDQ intrinsics
- Define the macro ``lucy_waitpkg`` to enable WAITPKG intrinsics
- Define the macro ``lucy_wbnoinvd`` to enable WBNOINVD intrinsics
- Define the macro ``lucy_xsave`` to enable XSAVE intrinsics
- Define the macro ``lucy_xsavec`` to enable XSAVEC intrinsics
- Define the macro ``lucy_xsaveopt`` to enable XSAVEOPT intrinsics
- Define the macro ``lucy_xss`` to enable XSS intrinsics


## Documentation

The documentation's layout is the same as the source's layout:

If you want to consult the documentation of ``Source/Meta/Same.hpp``, head to ``Documentation/Meta/Same.md``.

I recommend using a Markdown renderer for reading the .md files, such as Obsidian.


## Profiles

Lucy supports the different profiles proposed for C++, that target different needs based on safety.

The following profiles are supported:

- ``Type``: Ensures type safety. By enabling this profile, every object will be guaranteed to be initialised. To enable it, define the macro ``lucy_type_profile``.
- ``Memory``: Ensures memory safety. By enabling this profile, raw pointers will be safer. To enable it, define the macro ``lucy_memory_profile``.
- ``Concurrency``: Ensures thread safety. By enabling this profile, data races and deadlocks will be mitigated. To enable it, define the macro ``lucy_concurrency_profile``.

If you want multiple profiles, define their respective macros.

If you don't want to use profiles, don't define any of these mentioned macros.