cmake_minimum_required(VERSION 3.6)
project(openmp_test_clion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES basic_hello.cpp )
add_executable(basic_hello ${SOURCE_FILES})

set(SOURCE_FILES work_sharing.cpp )
add_executable(work_sharing ${SOURCE_FILES})

set(SOURCE_FILES parallel_for.cpp )
add_executable(parallel_for ${SOURCE_FILES})