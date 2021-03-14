include(GoogleTest)
find_package(GTest REQUIRED)

add_executable(test_fw test_fw.cpp)
target_link_libraries(test_fw
    PRIVATE fw base
    PRIVATE GTest::GTest GTest::Main)
