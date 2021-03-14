project(learn-fw)
cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

enable_testing()

add_subdirectory(base)
add_subdirectory(procedure)
add_subdirectory(testing)
