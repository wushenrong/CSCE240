set(CSCE240_ASSIGNMENT5_HEADERS
    "${CSCE240_SOURCE_DIR}/include/assignment5/SongRecording.h"
    "${CSCE240_SOURCE_DIR}/include/assignment5/StreamingTrack.h")

add_library(program5classes SongRecording.cc StreamingTrack.cc
                            ${CSCE240_ASSIGNMENT5_HEADERS})

target_link_libraries(program5classes PRIVATE csce240_compiler_flags
                                              Microsoft.GSL::GSL)
target_include_directories(program5classes PUBLIC ../../include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/assignment5"
  PREFIX "Assignment 5 Header Files"
  FILES ${CSCE240_ASSIGNMENT5_HEADERS})
