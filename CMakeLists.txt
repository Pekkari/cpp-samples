cmake_minimum_required(VERSION 3.5)

project(dungeon-crawler-2020-9)

add_subdirectory(SFML)
IF (BUILD_TESTING)
    add_subdirectory(googletest)
ENDIF(BUILD_TESTING)
