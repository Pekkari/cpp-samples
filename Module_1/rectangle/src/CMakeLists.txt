cmake_minimum_required(VERSION 3.5)

add_executable(rectangle main.cpp rectangle.cpp)
target_link_libraries(rectangle PRIVATE librectangle)
target_include_directories(rectangle PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-rectangle ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/rectangle)
