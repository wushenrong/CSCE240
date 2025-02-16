add_executable(program1 assignment1/program1.cc)
target_link_libraries(program1 PRIVATE csce240_compiler_flags)

add_library(program2functions assignment2/program2functions.cc)
target_link_libraries(program2functions PRIVATE csce240_compiler_flags
                                                Microsoft.GSL::GSL)
target_include_directories(program2functions
                           PUBLIC "${PROJECT_SOURCE_DIR}/include")
