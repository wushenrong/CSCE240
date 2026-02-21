cmake_minimum_required(VERSION 3.15...4.2)

project(
  CSCE240
  VERSION 0.1.0
  LANGUAGES CXX)

option(ENABLE_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)
option(ENABLE_CODE_COVERAGE "Enable code coverage" OFF)
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(GCC_LIKE_CXX
      "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
  set(MSVC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

  add_library(csce240_compiler_flags INTERFACE)

  target_compile_features(csce240_compiler_flags INTERFACE cxx_std_20)
  set_target_properties(
    csce240_compiler_flags
    PROPERTIES CXX_STANDARD_REQUIRED YES
               CXX_EXTENSIONS OFF
               CXX_VISIBILITY_PRESET hidden
               VISIBILITY_INLINES_HIDDEN YES)

  target_compile_options(
    csce240_compiler_flags
    INTERFACE
      "$<${GCC_LIKE_CXX}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wpedantic;-Weffc++;-Wconversion;-Wsign-conversion>>"
      "$<${MSVC_LIKE_CXX}:$<BUILD_INTERFACE:/W4;/permissive-;/w44365>>")

  if(ENABLE_WARNINGS_AS_ERRORS)
    target_compile_options(
      csce240_compiler_flags
      INTERFACE "$<${GCC_LIKE_CXX}:$<BUILD_INTERFACE:-Werror>>"
                "$<${MSVC_LIKE_CXX}:$<BUILD_INTERFACE:/WX>>")
  endif()

  if(ENABLE_CODE_COVERAGE)
    if(MSVC)
      target_link_options(csce240_compiler_flags INTERFACE
                          "$<BUILD_INTERFACE:/PROFILE>")
    else()
      target_compile_options(csce240_compiler_flags
                             INTERFACE "$<BUILD_INTERFACE:--coverage>")
      target_link_options(csce240_compiler_flags INTERFACE
                          "$<BUILD_INTERFACE:--coverage>")
      target_link_libraries(csce240_compiler_flags INTERFACE gcov)

      find_program(LCOV lcov REQUIRED)
      find_program(GENHTML genhtml REQUIRED)

      add_custom_target(
        coverage
        COMMAND ${LCOV} --directory . --capture --output-file coverage.info
        COMMAND ${GENHTML} --demangle-cpp -o coverage coverage.info
        WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")
    endif()
  endif()

  include(GenerateExportHeader)
  include(CTest)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

find_package(Microsoft.GSL CONFIG REQUIRED)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
