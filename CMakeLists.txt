cmake_minimum_required(VERSION 3.15...3.31)

project(
  CSCE240
  VERSION 0.0.0
  LANGUAGES CXX)

# Options for building the project
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(ENABLE_CODE_COVERAGE "Enable coverage reporting" OFF)
option(USE_VCPKG "Use vcpkg instead of FetchContent" OFF)

# Set compiler flags
add_library(csce240_compiler_flags INTERFACE)
target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(gcc_warning_flags
    "-Wall;-Wextra;-Wconversion;-Wsign-conversion;-pedantic-errors;-Werror")
set(msvc_warning_flags "/W4;/w44365;/permissive-;/WX")

set(gcc_build_flags "$<$<CONFIG:Debug>:-Og;-ggdb>")
set(msvc_build_flags "$<$<CONFIG:Debug>:/ZI>" "$<$<CONFIG:Release>:/Oi;/Gl;/Gy>" "/sdl;/utf-8;/Gs")

set(gcc_compile_flags "${gcc_warning_flags};${gcc_build_flags}")
set(msvc_compile_flags "${msvc_warning_flags};${msvc_build_flags}")

target_compile_options(
  csce240_compiler_flags
  INTERFACE "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_compile_flags}>>"
            "$<${msvc_cxx}:$<BUILD_INTERFACE:${msvc_compile_flags}>>")

target_link_options(
  csce240_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:${gcc_warning_flags}>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:/WX>>")

# Get dependencies
if(USE_VCPKG)
  find_package(Microsoft.GSL CONFIG REQUIRED)
  find_package(Catch2 CONFIG REQUIRED)
else()
  include(FetchContent)

  FetchContent_Declare(
    GSL
    GIT_REPOSITORY https://github.com/microsoft/GSL
    GIT_TAG v4.1.0
    GIT_SHALLOW ON)
  FetchContent_MakeAvailable(GSL)

  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.0)
  FetchContent_MakeAvailable(Catch2)
  list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")
endif()

# Add testing modules
include(CTest)
include(Catch)

# Code coverage from https://github.com/claremacrae/catch_cmake_coverage MIT
# License
if(ENABLE_CODE_COVERAGE AND !MSVC)
  message(STATUS "Enable Code Coverage")

  # --- Coverage specific configuration --- start add the project specific cmake
  # modules directory to the cmake module path (w.r.t. CI/CD builds this is not
  # the best approach)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

  # include the cmake code coverage module
  include(CodeCoverage)

  # Update the default compiler flags to enable coverage
  append_coverage_compiler_flags()

  # exclude /test directories from coverage analysis
  set(COVERAGE_LCOV_EXCLUDES "test/*")

  # cmake code coverage module target
  setup_target_for_coverage_lcov(
    NAME assignment2_tests_coverage EXECUTABLE assignment2_tests DEPENDENCIES
    assignment2_tests)
  # --- Coverage specific configuration --- end
endif()

# Include source and test code
add_subdirectory(src)
add_subdirectory(test)
