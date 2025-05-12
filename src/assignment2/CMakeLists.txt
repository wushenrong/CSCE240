add_library(program2functions program2functions.cc)
target_link_libraries(program2functions PRIVATE csce240_compiler_flags
                                                Microsoft.GSL::GSL)
target_include_directories(
  program2functions PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
                           "$<INSTALL_INTERFACE:include>")
