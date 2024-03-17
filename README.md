![logo](https://github.com/ContingencyOfTautologicalContradictions/Lucy/blob/main/Logo.png)

A modern, C++23 multi-platform game engine, with a focus on safety, performance and completeness.


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

The supported systems for now are ``macOS (arm64)``, ``iOS (arm64)``, ``Android (arm64)``, ``Linux (arm64, risc-v, amd64)``, and ``Windows (amd64)``.

The general requirements for any of these supported platforms are:

- 64-bits address space
- Git 2.44+

The following requirements are specific of each system:
  
### For macOS

- Define the macro ``lucy_mac``
- Latest macOS (14.4+)
- Latest XCode (15.3+)
- A GPU supporting Metal Shading Language 3.1+

### For iOS

- Define the macro ``lucy_ios``
- Latest iOS (17.4+)
- Latest iOS Simulator (17.4+)
- Latest macOS (14.4+)
- Latest XCode (15.3+)
- A GPU supporting Metal Shading Language 3.1+

### For Android

- Define the macro ``lucy_android``
- Latest Android Studio (3.2.1+)
- Latest Gradle (8.2+)
- A GPU supporting Vulkan 1.3+

### For Linux

- Define the macro ``lucy_linux``
- Latest Linux kernel
- Latest Wayland library (1.21+)
- Latest GCC (14+)
- Latest Vulkan (1.3+)
- A GPU supporting Vulkan 1.3+

### For Windows

- Define the macro ``lucy_windows``
- Latest Windows 11+
- Latest Visual Studio 2022 (17.6+)
- Latest Windows 11 Kit (10.0.22621+)
- A GPU supporting the latest D3D12+


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