set(CSCE240_ASSIGNMENT3_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment3/word_search_functions.h")

add_library(wordsearchfunctions word_search_functions.cc
                                ${CSCE240_ASSIGNMENT3_HEADERS})

generate_export_header(
  wordsearchfunctions EXPORT_FILE_NAME
  "${PROJECT_BINARY_DIR}/include/wordsearchfunctions_export.h")

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(wordsearchfunctions
                             PUBLIC WORDSEARCHFUNCTIONS_STATIC_DEFINE)
endif()

target_link_libraries(wordsearchfunctions PRIVATE csce240_compiler_flags
                                                  Microsoft.GSL::GSL)

target_include_directories(
  wordsearchfunctions PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
target_include_directories(
  wordsearchfunctions SYSTEM
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>")

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment3"
  PREFIX "Assignment 3 Header Files"
  FILES ${CSCE240_ASSIGNMENT3_HEADERS})
