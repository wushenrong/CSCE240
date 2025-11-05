set(CSCE240_ASSIGNMENT3_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment3/word_search_functions.h")

add_library(wordsearchfunctions word_search_functions.cc
                                ${CSCE240_ASSIGNMENT3_HEADERS})

target_link_libraries(wordsearchfunctions PRIVATE csce240_compiler_flags
                                                  Microsoft.GSL::GSL)
target_include_directories(wordsearchfunctions PUBLIC ../../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment3"
  PREFIX "Assignment 3 Header Files"
  FILES ${CSCE240_ASSIGNMENT3_HEADERS})
