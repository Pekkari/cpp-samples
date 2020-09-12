cmake_minimum_required(VERSION 3.5)

project(simple_class)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/simple_class/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/simple_class/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/simple_class/bin)
add_subdirectory(include)
add_subdirectory(src)

