cmake_minimum_required(VERSION 3.3)
project(play_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES basic/divide.c)
add_executable(play_algorithm ${SOURCE_FILES})