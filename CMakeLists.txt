cmake_minimum_required(VERSION 3.5)

project(dungeon-crawler-2020-9)

set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(SFML)
IF (BUILD_TESTING)
    add_subdirectory(googletest)
ENDIF(BUILD_TESTING)
