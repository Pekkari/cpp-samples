cmake_minimum_required(VERSION 3.5)

IF (BUILD_TESTING)
    add_subdirectory(SFML)
    add_subdirectory(game)
    add_subdirectory(characters)
    add_subdirectory(items)
ENDIF(BUILD_TESTING)
