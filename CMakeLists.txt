cmake_minimum_required(VERSION 3.15...4.1)

project(
  CSCE240
  VERSION 0.1.0
  LANGUAGES C CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  add_library(csce240_compiler_flags INTERFACE)
  target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)
  set_target_properties(csce240_compiler_flags
                        PROPERTIES CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)
endif()

find_package(Microsoft.GSL CONFIG REQUIRED)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
