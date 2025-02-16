add_executable(assignment2_tests assignment2_test.cc)
target_link_libraries(
  assignment2_tests PRIVATE csce240_compiler_flags program2functions
                            Catch2::Catch2WithMain)
target_include_directories(assignment2_tests
                           PRIVATE "${PROJECT_SOURCE_DIR}/include")

catch_discover_tests(assignment2_tests)
