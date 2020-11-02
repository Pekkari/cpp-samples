cmake_minimum_required(VERSION 3.5)

add_executable(dungeon-crawler dungeon-crawler.cpp)
target_include_directories(dungeon-crawler PUBLIC ${PROJECT_SOURCE_DIR}/include)
