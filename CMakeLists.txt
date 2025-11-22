cmake_minimum_required(VERSION 3.15...4.2)

project(
  CSCE240
  VERSION 0.1.0
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(GCC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
  set(MSVC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

  add_library(csce240_compiler_flags INTERFACE)

  target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)
  set_target_properties(csce240_compiler_flags
                        PROPERTIES CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

  target_compile_options(csce240_compiler_flags INTERFACE
    "$<${GCC_LIKE_CXX}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wpedantic;-Weffc++;-Wconversion;-Wsign-conversion>>"
    "$<${MSVC_LIKE_CXX}:$<BUILD_INTERFACE:/W4;/permissive-;/w44365>>")

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)
endif()

find_package(Microsoft.GSL CONFIG REQUIRED)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
