cmake_minimum_required(VERSION 3.15)
project(
  CSCE240
  VERSION 0.0.1
  LANGUAGES CXX)

add_library(csce240_compiler_flags INTERFACE)
target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(
  csce240_compiler_flags
  INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Weffc++;-Wconversion;-Wsign-conversion;-Werror;-pedantic-errors>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W4;-w44365;-permissive-;-WX>>")

add_subdirectory(src)
