set(CSCE240_ASSIGNMENT6_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment6/multiplechoicequestion.h"
    "${CSCE240_SOURCE_DIR}/include/assignment6/shortanswerquestion.h"
    "${CSCE240_SOURCE_DIR}/include/assignment6/truefalsequestion.h")

add_library(program6classes multiplechoicequestion.cc shortanswerquestion.cc
                            truefalsequestion.cc ${CSCE240_ASSIGNMENT5_HEADERS})

generate_export_header(program6classes EXPORT_FILE_NAME
                       "${PROJECT_BINARY_DIR}/include/program6classes_export.h")

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(program6classes
                             PUBLIC PROGRAM6CLASSES_STATIC_DEFINE)
endif()

target_link_libraries(program6classes PRIVATE csce240_compiler_flags
                                              gsl-lite::gsl-lite)

target_include_directories(
  program6classes PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
target_include_directories(
  program6classes SYSTEM
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>")

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment6"
  PREFIX "Assignment 6 Header Files"
  FILES ${CSCE240_ASSIGNMENT5_HEADERS})
