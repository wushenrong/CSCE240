add_library(program5classes SongRecording.cc StreamingTrack.cc)
target_link_libraries(program5classes PRIVATE csce240_compiler_flags
                                              Microsoft.GSL::GSL)
target_include_directories(
  program5classes PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
                         "$<INSTALL_INTERFACE:include>")
