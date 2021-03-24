# This file sets up a CMakeCache for the second stage of a Fuchsia toolchain build.

set(LLVM_TARGETS_TO_BUILD X86;ARM;AArch64;RISCV CACHE STRING "")

set(PACKAGE_VENDOR Fuchsia CACHE STRING "")

set(LLVM_ENABLE_PROJECTS "clang;clang-tools-extra;lld;llvm;polly" CACHE STRING "")
set(LLVM_ENABLE_RUNTIMES "compiler-rt;libcxx;libcxxabi;libunwind" CACHE STRING "")

set(LLVM_ENABLE_BACKTRACES OFF CACHE BOOL "")
if(NOT APPLE)
  set(LLVM_ENABLE_LLD ON CACHE BOOL "")
endif()
set(LLVM_ENABLE_LTO ON CACHE BOOL "")
set(LLVM_ENABLE_PER_TARGET_RUNTIME_DIR ON CACHE BOOL "")
set(LLVM_ENABLE_TERMINFO OFF CACHE BOOL "")
set(LLVM_ENABLE_UNWIND_TABLES OFF CACHE BOOL "")
set(LLVM_ENABLE_ZLIB ON CACHE BOOL "")
set(LLVM_INCLUDE_DOCS OFF CACHE BOOL "")
set(LLVM_INCLUDE_EXAMPLES OFF CACHE BOOL "")
set(LLVM_INCLUDE_GO_TESTS OFF CACHE BOOL "")
set(LLVM_USE_RELATIVE_PATHS_IN_FILES ON CACHE BOOL "")
set(LLVM_ENABLE_Z3_SOLVER OFF CACHE BOOL "")

if(MSVC)
  set(LLVM_USE_CRT_RELEASE "MT" CACHE STRING "")
endif()

set(CLANG_DEFAULT_CXX_STDLIB libc++ CACHE STRING "")
if(NOT APPLE)
  set(CLANG_DEFAULT_LINKER lld CACHE STRING "")
  set(CLANG_DEFAULT_OBJCOPY llvm-objcopy CACHE STRING "")
endif()
set(CLANG_DEFAULT_RTLIB compiler-rt CACHE STRING "")
set(CLANG_ENABLE_ARCMT OFF CACHE BOOL "")
set(CLANG_ENABLE_STATIC_ANALYZER ON CACHE BOOL "")
set(CLANG_PLUGIN_SUPPORT OFF CACHE BOOL "")

set(ENABLE_EXPERIMENTAL_NEW_PASS_MANAGER ON CACHE BOOL "")
set(ENABLE_LINKER_BUILD_ID ON CACHE BOOL "")
set(ENABLE_X86_RELAX_RELOCATIONS ON CACHE BOOL "")

set(CMAKE_BUILD_TYPE Release CACHE STRING "")
if (APPLE)
  set(MACOSX_DEPLOYMENT_TARGET 10.7 CACHE STRING "")
elseif(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded" CACHE STRING "")
endif()

if(APPLE)
  list(APPEND BUILTIN_TARGETS "default")
  list(APPEND RUNTIME_TARGETS "default")

  set(COMPILER_RT_ENABLE_TVOS OFF CACHE BOOL "")
  set(COMPILER_RT_ENABLE_WATCHOS OFF CACHE BOOL "")
  set(COMPILER_RT_USE_BUILTINS_LIBRARY ON CACHE BOOL "")

  set(LIBUNWIND_ENABLE_SHARED OFF CACHE BOOL "")
  set(LIBUNWIND_INSTALL_LIBRARY OFF CACHE BOOL "")
  set(LIBUNWIND_USE_COMPILER_RT ON CACHE BOOL "")
  set(LIBCXXABI_ENABLE_SHARED OFF CACHE BOOL "")
  set(LIBCXXABI_ENABLE_STATIC_UNWINDER ON CACHE BOOL "")
  set(LIBCXXABI_INSTALL_LIBRARY OFF CACHE BOOL "")
  set(LIBCXXABI_USE_COMPILER_RT ON CACHE BOOL "")
  set(LIBCXXABI_USE_LLVM_UNWINDER ON CACHE BOOL "")
  set(LIBCXX_USE_COMPILER_RT ON CACHE BOOL "")
  set(LIBCXX_ENABLE_SHARED OFF CACHE BOOL "")
  set(LIBCXX_ENABLE_STATIC_ABI_LIBRARY ON CACHE BOOL "")
  set(LIBCXX_ABI_VERSION 2 CACHE STRING "")
  set(DARWIN_ios_ARCHS armv7;armv7s;arm64 CACHE STRING "")
  set(DARWIN_iossim_ARCHS i386;x86_64 CACHE STRING "")
  set(DARWIN_osx_ARCHS arm64;x86_64 CACHE STRING "")
  set(SANITIZER_MIN_OSX_VERSION 10.7 CACHE STRING "")
endif()

if(WIN32)
  set(target "x86_64-pc-windows-msvc")

  list(APPEND BUILTIN_TARGETS "${target}")
  set(BUILTINS_${target}_CMAKE_SYSTEM_NAME Windows CACHE STRING "")
  set(BUILTINS_${target}_CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")

  list(APPEND RUNTIME_TARGETS "${target}")
  set(RUNTIMES_${target}_CMAKE_SYSTEM_NAME Windows CACHE STRING "")
  set(RUNTIMES_${target}_CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")
  set(RUNTIMES_${target}_LIBCXX_ABI_VERSION 2 CACHE STRING "")
  set(RUNTIMES_${target}_LIBCXX_ENABLE_EXPERIMENTAL_LIBRARY OFF CACHE BOOL "")
  set(RUNTIMES_${target}_LIBCXX_ENABLE_FILESYSTEM OFF CACHE BOOL "")
  set(RUNTIMES_${target}_LIBCXX_ENABLE_ABI_LINKER_SCRIPT OFF CACHE BOOL "")
  set(RUNTIMES_${target}_LIBCXX_ENABLE_SHARED OFF CACHE BOOL "")
  set(RUNTIMES_${target}_LLVM_ENABLE_RUNTIMES "compiler-rt;libcxx" CACHE STRING "")
endif()

foreach(target aarch64-unknown-linux-gnu;armv7-unknown-linux-gnueabihf;i386-unknown-linux-gnu;x86_64-unknown-linux-gnu)
  if(LINUX_${target}_SYSROOT)
    # Set the per-target builtins options.
    list(APPEND BUILTIN_TARGETS "${target}")
    set(BUILTINS_${target}_CMAKE_SYSTEM_NAME Linux CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_C_FLAGS "--target=${target}" CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_CXX_FLAGS "--target=${target}" CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_ASM_FLAGS "--target=${target}" CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_SYSROOT ${LINUX_${target}_SYSROOT} CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_SHARED_LINKER_FLAGS "-fuse-ld=lld" CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_MODULE_LINKER_FLAGS "-fuse-ld=lld" CACHE STRING "")
    set(BUILTINS_${target}_CMAKE_EXE_LINKER_FLAG "-fuse-ld=lld" CACHE STRING "")

    # Set the per-target runtimes options.
    list(APPEND RUNTIME_TARGETS "${target}")
    set(RUNTIMES_${target}_CMAKE_SYSTEM_NAME Linux CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_C_FLAGS "--target=${target}" CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_CXX_FLAGS "--target=${target}" CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_ASM_FLAGS "--target=${target}" CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_SYSROOT ${LINUX_${target}_SYSROOT} CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_SHARED_LINKER_FLAGS "-fuse-ld=lld" CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_MODULE_LINKER_FLAGS "-fuse-ld=lld" CACHE STRING "")
    set(RUNTIMES_${target}_CMAKE_EXE_LINKER_FLAGS "-fuse-ld=lld" CACHE STRING "")
    set(RUNTIMES_${target}_COMPILER_RT_USE_BUILTINS_LIBRARY ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBUNWIND_ENABLE_SHARED OFF CACHE BOOL "")
    set(RUNTIMES_${target}_LIBUNWIND_USE_COMPILER_RT ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBUNWIND_INSTALL_LIBRARY OFF CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXXABI_USE_COMPILER_RT ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXXABI_ENABLE_SHARED OFF CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXXABI_USE_LLVM_UNWINDER ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXXABI_ENABLE_STATIC_UNWINDER ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXXABI_INSTALL_LIBRARY OFF CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXX_USE_COMPILER_RT ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXX_ENABLE_SHARED OFF CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXX_ENABLE_STATIC_ABI_LIBRARY ON CACHE BOOL "")
    set(RUNTIMES_${target}_LIBCXX_ABI_VERSION 2 CACHE STRING "")
    set(RUNTIMES_${target}_LLVM_ENABLE_ASSERTIONS ON CACHE BOOL "")
    set(RUNTIMES_${target}_SANITIZER_CXX_ABI "libc++" CACHE STRING "")
    set(RUNTIMES_${target}_SANITIZER_CXX_ABI_INTREE ON CACHE BOOL "")
    set(RUNTIMES_${target}_LLVM_ENABLE_RUNTIMES "compiler-rt;libcxx;libcxxabi;libunwind" CACHE STRING "")

    # Use .build-id link.
    list(APPEND RUNTIME_BUILD_ID_LINK "${target}")
  endif()
endforeach()

if(FUCHSIA_SDK)
  set(FUCHSIA_aarch64_NAME arm64)
  set(FUCHSIA_i386_NAME x64)
  set(FUCHSIA_x86_64_NAME x64)
  set(FUCHSIA_riscv64_NAME riscv64)
  foreach(target i386;x86_64;aarch64;riscv64)
    set(FUCHSIA_${target}_COMPILER_FLAGS "--target=${target}-unknown-fuchsia -I${FUCHSIA_SDK}/pkg/fdio/include")
    set(FUCHSIA_${target}_LINKER_FLAGS "-L${FUCHSIA_SDK}/arch/${FUCHSIA_${target}_NAME}/lib")
    set(FUCHSIA_${target}_SYSROOT "${FUCHSIA_SDK}/arch/${FUCHSIA_${target}_NAME}/sysroot")
  endforeach()

  foreach(target i386;x86_64;aarch64;riscv64)
    # Set the per-target builtins options.
    list(APPEND BUILTIN_TARGETS "${target}-unknown-fuchsia")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_SYSTEM_NAME Fuchsia CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_ASM_FLAGS ${FUCHSIA_${target}_COMPILER_FLAGS} CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_C_FLAGS ${FUCHSIA_${target}_COMPILER_FLAGS} CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_CXX_FLAGS ${FUCHSIA_${target}_COMPILER_FLAGS} CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_SHARED_LINKER_FLAGS ${FUCHSIA_${target}_LINKER_FLAGS} CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_MODULE_LINKER_FLAGS ${FUCHSIA_${target}_LINKER_FLAGS} CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_EXE_LINKER_FLAGS ${FUCHSIA_${target}_LINKER_FLAGS} CACHE STRING "")
    set(BUILTINS_${target}-unknown-fuchsia_CMAKE_SYSROOT ${FUCHSIA_${target}_SYSROOT} CACHE PATH "")
  endforeach()

  foreach(target x86_64;aarch64)
    # Set the per-target runtimes options.
    list(APPEND RUNTIME_TARGETS "${target}-unknown-fuchsia")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_SYSTEM_NAME Fuchsia CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_BUILD_WITH_INSTALL_RPATH ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_ASM_FLAGS ${FUCHSIA_${target}_COMPILER_FLAGS} CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_C_FLAGS ${FUCHSIA_${target}_COMPILER_FLAGS} CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_CXX_FLAGS ${FUCHSIA_${target}_COMPILER_FLAGS} CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_SHARED_LINKER_FLAGS ${FUCHSIA_${target}_LINKER_FLAGS} CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_MODULE_LINKER_FLAGS ${FUCHSIA_${target}_LINKER_FLAGS} CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_EXE_LINKER_FLAGS ${FUCHSIA_${target}_LINKER_FLAGS} CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_CMAKE_SYSROOT ${FUCHSIA_${target}_SYSROOT} CACHE PATH "")
    set(RUNTIMES_${target}-unknown-fuchsia_COMPILER_RT_USE_BUILTINS_LIBRARY ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBUNWIND_USE_COMPILER_RT ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBUNWIND_HIDE_SYMBOLS ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBUNWIND_INSTALL_STATIC_LIBRARY OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXXABI_USE_COMPILER_RT ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXXABI_USE_LLVM_UNWINDER ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXXABI_ENABLE_STATIC_UNWINDER ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXXABI_HERMETIC_STATIC_LIBRARY ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXXABI_INSTALL_STATIC_LIBRARY OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXXABI_STATICALLY_LINK_UNWINDER_IN_SHARED_LIBRARY OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXX_USE_COMPILER_RT ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXX_ENABLE_STATIC_ABI_LIBRARY ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXX_HERMETIC_STATIC_LIBRARY ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXX_STATICALLY_LINK_ABI_IN_SHARED_LIBRARY OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LIBCXX_ABI_VERSION 2 CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia_LLVM_ENABLE_ASSERTIONS ON CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia_LLVM_ENABLE_RUNTIMES "compiler-rt;libcxx;libcxxabi;libunwind" CACHE STRING "")

    set(RUNTIMES_${target}-unknown-fuchsia+asan_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan_LLVM_USE_SANITIZER "Address" CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan_LIBCXXABI_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan_LIBCXX_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")

    set(RUNTIMES_${target}-unknown-fuchsia+noexcept_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+noexcept_LIBCXXABI_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+noexcept_LIBCXX_ENABLE_EXCEPTIONS OFF CACHE BOOL "")

    set(RUNTIMES_${target}-unknown-fuchsia+asan+noexcept_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan+noexcept_LLVM_USE_SANITIZER "Address" CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan+noexcept_LIBCXXABI_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan+noexcept_LIBCXX_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan+noexcept_LIBCXXABI_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+asan+noexcept_LIBCXX_ENABLE_EXCEPTIONS OFF CACHE BOOL "")

    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables_CMAKE_CXX_FLAGS "${RUNTIMES_${target}-unknown-fuchsia+relative-vtables_CMAKE_CXX_FLAGS} -Xclang -fexperimental-relative-c++-abi-vtables" CACHE STRING "")

    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan_LLVM_USE_SANITIZER "Address" CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan_LIBCXXABI_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan_LIBCXX_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan_CMAKE_CXX_FLAGS "${RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan_CMAKE_CXX_FLAGS} -Xclang -fexperimental-relative-c++-abi-vtables" CACHE STRING "")

    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+noexcept_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+noexcept_CMAKE_CXX_FLAGS "${RUNTIMES_${target}-unknown-fuchsia+relative-vtables+noexcept_CMAKE_CXX_FLAGS} -Xclang -fexperimental-relative-c++-abi-vtables" CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+noexcept_LIBCXXABI_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+noexcept_LIBCXX_ENABLE_EXCEPTIONS OFF CACHE BOOL "")

    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_LLVM_BUILD_COMPILER_RT OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_LLVM_USE_SANITIZER "Address" CACHE STRING "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_LIBCXXABI_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_LIBCXX_ENABLE_NEW_DELETE_DEFINITIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_LIBCXXABI_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_LIBCXX_ENABLE_EXCEPTIONS OFF CACHE BOOL "")
    set(RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_CMAKE_CXX_FLAGS "${RUNTIMES_${target}-unknown-fuchsia+relative-vtables+asan+noexcept_CMAKE_CXX_FLAGS} -Xclang -fexperimental-relative-c++-abi-vtables" CACHE STRING "")

    # Use .build-id link.
    list(APPEND RUNTIME_BUILD_ID_LINK "${target}-unknown-fuchsia")
  endforeach()

  set(LLVM_RUNTIME_MULTILIBS "asan;noexcept;asan+noexcept;relative-vtables;relative-vtables+noexcept;relative-vtables+asan;relative-vtables+asan+noexcept" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_asan_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_noexcept_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_asan+noexcept_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_relative-vtables_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_relative-vtables+noexcept_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_relative-vtables+asan_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
  set(LLVM_RUNTIME_MULTILIB_relative-vtables+asan+noexcept_TARGETS "x86_64-unknown-fuchsia;aarch64-unknown-fuchsia" CACHE STRING "")
endif()

set(LLVM_BUILTIN_TARGETS "${BUILTIN_TARGETS}" CACHE STRING "")
set(LLVM_RUNTIME_TARGETS "${RUNTIME_TARGETS}" CACHE STRING "")

# Setup toolchain.
set(LLVM_INSTALL_TOOLCHAIN_ONLY ON CACHE BOOL "")
set(LLVM_TOOLCHAIN_TOOLS
  dsymutil
  llvm-ar
  llvm-cov
  llvm-cxxfilt
  llvm-dlltool
  llvm-dwarfdump
  llvm-dwp
  llvm-elfabi
  llvm-gsymutil
  llvm-lib
  llvm-lipo
  llvm-mt
  llvm-nm
  llvm-objcopy
  llvm-objdump
  llvm-profdata
  llvm-rc
  llvm-ranlib
  llvm-readelf
  llvm-readobj
  llvm-size
  llvm-strip
  llvm-symbolizer
  llvm-xray
  sancov
  CACHE STRING "")

set(LLVM_DISTRIBUTION_COMPONENTS
  clang
  lld
  LTO
  clang-apply-replacements
  clang-doc
  clang-format
  clang-resource-headers
  clang-include-fixer
  clang-refactor
  clang-scan-deps
  clang-tidy
  clangd
  builtins
  runtimes
  ${LLVM_TOOLCHAIN_TOOLS}
  CACHE STRING "")
