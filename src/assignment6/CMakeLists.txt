add_library(program6classes multiplechoicequestion.cc shortanswerquestion.cc
                            truefalsequestion.cc)
target_link_libraries(program6classes PRIVATE csce240_compiler_flags
                                              Microsoft.GSL::GSL)
target_include_directories(
  program6classes PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
                         "$<INSTALL_INTERFACE:include>")
