project(learn-fw)
cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

include(GoogleTest)
find_package(GTest REQUIRED)
enable_testing()

add_subdirectory(base)
add_subdirectory(oop)
add_subdirectory(testing)
