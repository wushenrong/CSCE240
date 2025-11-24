find_package(Catch2 CONFIG REQUIRED)

include(Catch)

add_executable(csce240_tests test_assignment2.cc test_assignment3.cc
                             test_assignment4.cc)

target_link_libraries(
  csce240_tests
  PRIVATE csce240_compiler_flags
          program2functions
          wordsearchfunctions
          program4functions
          program5classes
          program6classes
          Catch2::Catch2WithMain)

if(ENABLE_CODE_COVERAGE)
  if(MSVC)
    target_link_options(csce240_tests PRIVATE "$<BUILD_INTERFACE:/PROFILE>")
  else()
    target_compile_options(csce240_tests
                           PRIVATE "$<BUILD_INTERFACE:--coverage>")
    link_libraries(gcov)
  endif()
endif()

add_custom_command(
  TARGET csce240_tests
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t "$<TARGET_FILE_DIR:csce240_tests>"
          "${PROJECT_SOURCE_DIR}/tests/example_wordsearch.txt"
  COMMAND ${CMAKE_COMMAND} -E copy -t "$<TARGET_FILE_DIR:csce240_tests>"
          "${PROJECT_SOURCE_DIR}/tests/malformed_wordsearch.txt"
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:csce240_tests>
          $<TARGET_RUNTIME_DLLS:csce240_tests>
  COMMAND_EXPAND_LISTS)

catch_discover_tests(csce240_tests)
