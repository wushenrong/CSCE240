add_executable(csce240_tests test_assignment2.cc test_assignment3.cc)
target_link_libraries(
  csce240_tests PRIVATE csce240_compiler_flags program2functions
                        wordsearchfunctions Catch2::Catch2WithMain)

add_custom_command(
  TARGET csce240_tests
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:csce240_tests>
          ${CMAKE_CURRENT_SOURCE_DIR}/example_wordsearch.txt
  COMMAND_EXPAND_LISTS)

include(CTest)
include(Catch)
catch_discover_tests(csce240_tests)
