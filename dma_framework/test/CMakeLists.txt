add_executable(UT UT.cpp)
target_link_libraries(UT gtest_main)
add_test(NAME DUMMY_UT_test COMMAND UT)