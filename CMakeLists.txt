cmake_minimum_required(VERSION 3.15...3.31)

project(
  CSCE240
  VERSION 0.0.0
  LANGUAGES CXX)

# Options for building the project
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(ENABLE_CODE_COVERAGE "Enable coverage reporting" OFF)

# Set compiler flags
add_library(csce240_compiler_flags INTERFACE)
target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)

set(_gcc_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(_msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(
  csce240_compiler_flags
  INTERFACE
    "$<${_gcc_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Weffc++;-Wconversion;-Wsign-conversion;-pedantic-errors;-Werror>>"
    "$<${_msvc_cxx}:$<BUILD_INTERFACE:/W4;/w44365;/permissive-;/WX>>")

if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Get dependencies
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

# Add testing modules
include(CTest)
include(Catch)

# Code coverage from https://github.com/claremacrae/catch_cmake_coverage
if(ENABLE_CODE_COVERAGE AND !MSVC)
  message(STATUS "Enable Code Coverage")

  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
  include(CodeCoverage)

  append_coverage_compiler_flags()

  set(COVERAGE_LCOV_EXCLUDES "test/*")

  setup_target_for_coverage_lcov(
    NAME assignment2_tests_coverage EXECUTABLE assignment2_tests DEPENDENCIES
    assignment2_tests)
endif()

# Include source and test code
add_subdirectory(src)
add_subdirectory(test)
