cmake_minimum_required(VERSION 3.5)

project(vector_strings)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/vector_strings/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/vector_strings/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/vector_strings/bin)
add_subdirectory(include)
add_subdirectory(src)

