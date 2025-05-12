add_library(program4functions weight.cc weightrange.cc)
target_link_libraries(program4functions PRIVATE csce240_compiler_flags)
target_include_directories(
  program4functions PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
                           "$<INSTALL_INTERFACE:include>")
