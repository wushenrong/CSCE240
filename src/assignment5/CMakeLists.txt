set(CSCE240_ASSIGNMENT5_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment5/SongRecording.h"
    "${CSCE240_SOURCE_DIR}/include/assignment5/StreamingTrack.h")

add_library(program5classes SongRecording.cc StreamingTrack.cc
                            ${CSCE240_ASSIGNMENT5_HEADERS})

generate_export_header(program5classes EXPORT_FILE_NAME
                       "${PROJECT_BINARY_DIR}/include/program5classes_export.h")

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(program5classes
                             PUBLIC PROGRAM5CLASSES_STATIC_DEFINE)
endif()

target_link_libraries(program5classes PRIVATE csce240_compiler_flags
                                              gsl-lite::gsl-lite)

target_include_directories(
  program5classes PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
target_include_directories(
  program5classes SYSTEM
  PUBLIC "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>")

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment5"
  PREFIX "Assignment 5 Header Files"
  FILES ${CSCE240_ASSIGNMENT5_HEADERS})
