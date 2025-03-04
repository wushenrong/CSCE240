add_executable(csce240_tests assignment2_test.cc assignment3_test.cc)
target_link_libraries(
  csce240_tests
  PRIVATE csce240_compiler_flags program2functions wordsearchfunctions
          Catch2::Catch2 Catch2::Catch2WithMain)
target_include_directories(csce240_tests
                           PRIVATE "${PROJECT_SOURCE_DIR}/include")

add_custom_command(
  TARGET csce240_tests
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:csce240_tests>
          ${CMAKE_CURRENT_SOURCE_DIR}/example_wordsearch.txt
  COMMAND_EXPAND_LISTS)

if(WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(
    TARGET csce240_tests
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:csce240_tests>
            $<TARGET_RUNTIME_DLLS:csce240_tests>
    COMMAND_EXPAND_LISTS)
endif()

catch_discover_tests(csce240_tests)
