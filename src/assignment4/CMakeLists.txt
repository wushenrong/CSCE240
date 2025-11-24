set(CSCE240_ASSIGNMENT4_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment4/weight.h"
    "${CSCE240_SOURCE_DIR}/include/assignment4/weightrange.h")

add_library(program4functions weight.cc weightrange.cc
                              ${CSCE240_ASSIGNMENT4_HEADERS})

generate_export_header(
  program4functions EXPORT_FILE_NAME
  "${PROJECT_BINARY_DIR}/include/program4functions_export.h")

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(program4functions
                             PUBLIC PROGRAM4FUNCTIONS_STATIC_DEFINE)
endif()

target_link_libraries(program4functions PRIVATE csce240_compiler_flags)

target_include_directories(
  program4functions PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
target_include_directories(
  program4functions SYSTEM
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>")

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment4"
  PREFIX "Assignment 4 Header Files"
  FILES ${CSCE240_ASSIGNMENT4_HEADERS})
