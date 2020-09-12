cmake_minimum_required(VERSION 3.5)

project(first_touch)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/first_touch/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/first_touch/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/first_touch/bin)
add_subdirectory(include)
add_subdirectory(src)

