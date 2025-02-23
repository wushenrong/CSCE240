add_executable(assignment2_tests assignment2_test.cc)
target_link_libraries(
  assignment2_tests PRIVATE csce240_compiler_flags program2functions
                            Catch2::Catch2WithMain)
target_include_directories(assignment2_tests
                           PRIVATE "${PROJECT_SOURCE_DIR}/include")

if(WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(
    TARGET assignment2_tests
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:assignment2_tests>
            $<TARGET_RUNTIME_DLLS:assignment2_tests>
    COMMAND_EXPAND_LISTS)
endif()

catch_discover_tests(assignment2_tests)
