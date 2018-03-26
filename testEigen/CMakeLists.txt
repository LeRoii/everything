cmake_minimum_required(VERSION 3.2)
project(TestEigen)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories("/usr/include/eigen3")

add_executable(e testEigen.cpp)