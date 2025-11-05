set(CSCE240_ASSIGNMENT2_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment2/program2functions.h")

add_library(program2functions program2functions.cc
                              ${CSCE240_ASSIGNMENT2_HEADERS})

target_link_libraries(program2functions PRIVATE csce240_compiler_flags
                                                Microsoft.GSL::GSL)
target_include_directories(program2functions PUBLIC ../../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment2"
  PREFIX "Assignment 2 Header Files"
  FILES ${CSCE240_ASSIGNMENT2_HEADERS})
