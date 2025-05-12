cmake_minimum_required(VERSION 3.10)
project(formatter)
add_library(formatter STATIC formatter.cpp)
target_include_directories(formatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})