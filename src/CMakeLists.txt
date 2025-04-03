add_executable(program1 assignment1/program1.cc)
target_link_libraries(program1 PRIVATE csce240_compiler_flags)

add_library(program2functions assignment2/program2functions.cc)
target_link_libraries(program2functions PRIVATE csce240_compiler_flags
                                                Microsoft.GSL::GSL)
target_include_directories(program2functions
                           PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(wordsearchfunctions assignment3/word_search_functions.cc)
target_link_libraries(wordsearchfunctions PRIVATE csce240_compiler_flags
                                                  Microsoft.GSL::GSL)
target_include_directories(wordsearchfunctions
                           PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(program4functions assignment4/weight.cc assignment4/weightrange.cc)
target_include_directories(program4functions
                           PUBLIC "${PROJECT_SOURCE_DIR}/include")
