set(CSCE240_ASSIGNMENT6_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment6/multiplechoicequestion.h"
    "${CSCE240_SOURCE_DIR}/include/assignment6/shortanswerquestion.h"
    "${CSCE240_SOURCE_DIR}/include/assignment6/truefalsequestion.h")

add_library(program6classes multiplechoicequestion.cc shortanswerquestion.cc
                            truefalsequestion.cc ${CSCE240_ASSIGNMENT5_HEADERS})

target_link_libraries(program6classes PRIVATE csce240_compiler_flags
                                              Microsoft.GSL::GSL)
target_include_directories(program6classes PUBLIC ../../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment6"
  PREFIX "Assignment 6 Header Files"
  FILES ${CSCE240_ASSIGNMENT5_HEADERS})
