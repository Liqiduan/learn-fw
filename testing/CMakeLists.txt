add_executable(test_fw test_table.cpp)
target_link_libraries(test_fw
    PRIVATE fw base
    PRIVATE GTest::GTest GTest::Main)
gtest_add_tests(TARGET test_fw)
