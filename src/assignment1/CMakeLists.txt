add_executable(program1 program1.cc)

target_link_libraries(program1 PRIVATE csce240_compiler_flags
                                       Microsoft.GSL::GSL)
