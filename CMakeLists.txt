cmake_minimum_required(VERSION 3.15...3.31)

project(
  CSCE240
  VERSION 0.0.0
  LANGUAGES CXX)

option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)

set(GCC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Set compiler flags
add_library(csce240_compiler_flags INTERFACE)
target_compile_features(csce240_compiler_flags INTERFACE cxx_std_17)

target_compile_options(
  csce240_compiler_flags
  INTERFACE
    "$<${GCC_LIKE_CXX}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wpedantic;-Weffc++>>"
    "$<${GCC_LIKE_CXX}:$<BUILD_INTERFACE:-Wconversion;-Wsign-conversion>>"
    "$<${MSVC_LIKE_CXX}:$<BUILD_INTERFACE:-W4;-permissive-;-w44365>>")

if(ENABLE_WARNINGS_AS_ERRORS)
  target_compile_options(
    csce240_compiler_flags
    INTERFACE "$<${GCC_LIKE_CXX}:$<BUILD_INTERFACE:-Werror>>"
              "$<${MSVC_LIKE_CXX}:$<BUILD_INTERFACE:-WX>>")
endif()

target_compile_options(csce240_compiler_flags
                       INTERFACE "$<${MSVC_LIKE_CXX}:$<$<CONFIG:Debug>:-Zi>>")

if(ENABLE_COVERAGE)
  target_compile_options(csce240_compiler_flags "$<${GCC_LIKE_CXX}:--coverage>")
  link_libraries(gcov)
endif()

# Get dependencies
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

add_subdirectory(src/assignment1)
add_subdirectory(src/assignment2)
add_subdirectory(src/assignment3)
add_subdirectory(src/assignment4)
add_subdirectory(src/assignment5)

enable_testing()
add_subdirectory(tests)
