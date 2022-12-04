cmake_minimum_required(VERSION 3.22)
project(Cpp_Vector)

set(CMAKE_CXX_STANDARD 23)

include_directories(inc)
file(GLOB_RECURSE SOURCES "src/*.*")

add_executable(Cpp_Vector main.cpp ${SOURCES})
