# Lucy

A modern, C++26 multi-platform general-purpose library, specifically designed as an SDK for your games, with a focus on safety, performance and completeness.

## Compilers

Lucy supports GCC, MSVC, Apple Clang, and Clang.

## Versioning

At your build system of preference, define various macros for the versioning, which are:

- lucy_major: the major version number
- lucy_middle: the middle version number
- lucy_minor: the minor version number

For example, if the Lucy's version you want to target is 3.0.1, these macros should be defined as:

lucy_major: 3
lucy_middle: 0
lucy_minor: 1

The actual version is 0.0.1.

## Requirements

The supported systems for now are macOS (arm64), iOS (arm64), Android (arm64), Linux (arm64, risc-v64, amd64), and Windows (amd64).

The general requirements for any of these supported platforms are:

- 64-bits address space
- Git 2.46.0+

The following requirements are specific of each system:

### For macOS

- Define the macro lucy_arm64
- Define the macro lucy_mac
- Latest macOS (16.0+)
- Latest XCode (17.0+)
- A GPU supporting Metal Shading Language 3.1+

### For iOS

- Define the macro lucy_arm64
- Define the macro lucy_ios
- Latest iOS (19.0+)
- Latest iOS Simulator (19.0+)
- Latest macOS (16.0+)
- Latest XCode (17.0+)
- A GPU supporting Metal Shading Language 3.1+

### For Android

- Define the macro lucy_arm64
- Define the macro lucy_android
- Latest Android NDK (R27+)
- Latest Android SDK (35+)
- Latest Android Studio (2024.1.1+)
- Latest Gradle (8.10+)
- A GPU supporting Vulkan 1.3+

### For Linux

- Define the macro lucy_arm64, lucy_amd64, or lucy_riscv64, depending on the architecture you target
- Define the macro lucy_linux
- Latest Linux kernel
- Latest Wayland library (1.22+)
- Latest GCC (15+)
- Latest Vulkan (1.3+)
- A GPU supporting Vulkan 1.3+

### For Windows

- Define the macro lucy_amd64
- Define the macro lucy_windows
- Latest Windows 11+
- Latest Visual Studio 2022 (17.6+)
- Latest Windows 11 SDK (10.0.22621+)
- A GPU supporting the latest D3D12+