cmake_minimum_required(VERSION 3.10)
project(solver_lib)

add_library(solver STATIC solver.cpp solver.h)
target_include_directories(solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
