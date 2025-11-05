set(CSCE240_ASSIGNMENT4_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment4/weight.h"
    "${CSCE240_SOURCE_DIR}/include/assignment4/weightrange.h")

add_library(program4functions weight.cc weightrange.cc
                              ${CSCE240_ASSIGNMENT4_HEADERS})

target_link_libraries(program4functions PRIVATE csce240_compiler_flags)
target_include_directories(program4functions PUBLIC ../../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment4"
  PREFIX "Assignment 4 Header Files"
  FILES ${CSCE240_ASSIGNMENT4_HEADERS})
