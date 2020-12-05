cmake_minimum_required(VERSION 3.5)

project(dungeon-crawler)

set(dungeon-crawler_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(dungeon-crawler_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Use `CMAKE_BUILD_TYPE=Debug cmake ..`
# to build the debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "-g")

include_directories(include)
include_directories(SFML/include)

add_subdirectory(SFML)
add_subdirectory(include)
add_subdirectory(src)
IF (BUILD_TESTING)
    include_directories(googletest/googletest)
    include_directories(googletest/googlemock)
    add_subdirectory(googletest)
ENDIF(BUILD_TESTING)
