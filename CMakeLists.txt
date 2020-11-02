cmake_minimum_required(VERSION 3.5)

project(dungeon-crawler-2020-9)

set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(SFML)
add_subdirectory(src)
IF (BUILD_TESTING)
    add_subdirectory(googletest)
ENDIF(BUILD_TESTING)
