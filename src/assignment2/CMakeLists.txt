set(CSCE240_ASSIGNMENT2_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment2/program2functions.h")

add_library(program2functions program2functions.cc
                              ${CSCE240_ASSIGNMENT2_HEADERS})

generate_export_header(
  program2functions EXPORT_FILE_NAME
  "${PROJECT_BINARY_DIR}/include/program2functions_export.h")

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(program2functions
                             PUBLIC PROGRAM2FUNCTIONS_STATIC_DEFINE)
endif()

target_link_libraries(program2functions PRIVATE csce240_compiler_flags
                                                gsl-lite::gsl-lite)

target_include_directories(
  program2functions PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
target_include_directories(
  program2functions SYSTEM
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>")

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment2"
  PREFIX "Assignment 2 Header Files"
  FILES ${CSCE240_ASSIGNMENT2_HEADERS})
