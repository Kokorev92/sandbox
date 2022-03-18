cmake_minimum_required(VERSION 3.21)
project(scale_class)

set(CMAKE_CXX_STANDARD 17)

add_executable(tests main.cpp)

target_link_libraries(tests PUBLIC gtest pthread)
