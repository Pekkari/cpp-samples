cmake_minimum_required(VERSION 3.5)

add_executable(dungeon-crawler dungeon-crawler.cpp)
target_link_libraries(dungeon-crawler PRIVATE libinput libgame libcharacter libenemy libnpc libplayer libitem libconsumable libequipment)
target_include_directories(dungeon-crawler PUBLIC ${PROJECT_SOURCE_DIR}/include)
