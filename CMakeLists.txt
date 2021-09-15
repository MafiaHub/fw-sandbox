cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0091 NEW)
project(Sandbox CXX)

include_directories(${PROJECT_SOURCE_DIR}/code/framework/src/)

add_subdirectory(vendors)
add_subdirectory(code)
