add_library(wordsearchfunctions word_search_functions.cc)
target_link_libraries(wordsearchfunctions PRIVATE csce240_compiler_flags
                                                  Microsoft.GSL::GSL)
target_include_directories(
  wordsearchfunctions PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
                             "$<INSTALL_INTERFACE:include>")
