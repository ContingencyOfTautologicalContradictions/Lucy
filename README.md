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


## Requirements

- 64-bits address space
- Git 2.44+
- CMake 3.28.3+
- Ninja 1.11.1+
  
### For macOS and iOS

- Latest macOS (14.3.1+)
- Latest iOS Simulator (17.3.1+)
- Latest XCode (15.2+)
- A GPU capable of running the Metal Shading Language 3.1+

### For Android

- Latest Android Studio (3.2.1+)
- Latest Gradle (8.2+)
- A mobile-device capable of running Vulkan 1.3+

### For Linux

- Latest Linux kernel
- Latest Wayland library (1.20+)
- Latest GCC (14+)
- Latest Vulkan (1.3+)
- A GPU capable of running Vulkan 1.3+

### For Windows

- Latest Windows 11+
- Latest Visual Studio 2022 (17.6+)
- Latest Windows 11 Kit (10.0.22621+)
- A GPU capable of running D3D12+


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

If you want multiple profiles, then simply define their respective macros for the same build.

If you don't want to use profiles, simply don't define any of these mentioned macros.