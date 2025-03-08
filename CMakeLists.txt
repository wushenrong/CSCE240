cmake_minimum_required(VERSION 3.15...3.31)

project(
  CSCE240
  VERSION 0.0.0
  LANGUAGES CXX)

# Options for building the project
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# Set compiler flags
add_library(csce240_compiler_flags INTERFACE)
target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)

set(_gcc_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(_msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

set(_gcc_warning_flags "-Wall;-Wextra;-Wpedantic;-Werror;-Weffc++;-Wconversion"
                       "-Wsign-conversion;-Wformat=2")
set(_msvc_warning_flags "/W4;/permissive-;/WX;/w44365;")

set(_gcc_compile_flags "$<$<CONFIG:Debug>:-ggdb;-Og>"
                       "$<$<CONFIG:Release>:-flto>")
set(_msvc_compile_flags "$<$<CONFIG:Debug>:/ZI>"
                        "$<$<CONFIG:Release>:/Oi;/GL;/Gy>" "/Gs;/sdl;/guard:cf")

set(_gcc_flags "${_gcc_warning_flags};${_gcc_compile_flags}")
set(_msvc_flags "${_msvc_warning_flags};${_msvc_compile_flags}")

target_compile_options(
  csce240_compiler_flags
  INTERFACE "$<${_gcc_cxx}:$<BUILD_INTERFACE:${_gcc_flags}>>"
            "$<${_msvc_cxx}:$<BUILD_INTERFACE:${_msvc_flags}>>")

# Get dependencies
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

# Add testing modules
include(CTest)
include(Catch)

# Code coverage from https://github.com/claremacrae/catch_cmake_coverage
if(ENABLE_CODE_COVERAGE AND NOT MSVC)
  message(STATUS "Enable Code Coverage")

  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
  include(CodeCoverage)

  append_coverage_compiler_flags()

  set(COVERAGE_LCOV_EXCLUDES "/usr/include/*" "build/*" "tests/*")

  setup_target_for_coverage_lcov(NAME csce240_tests_coverage EXECUTABLE
                                 csce240_tests DEPENDENCIES csce240_tests)
endif()

# Include source and test code
add_subdirectory(src)
add_subdirectory(tests)
