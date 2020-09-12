cmake_minimum_required(VERSION 3.5)

add_executable(dog_class main.cpp dog_class.cpp)
target_link_libraries(dog_class PRIVATE libdog_class)
target_include_directories(dog_class PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-dog_class ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dog_class)
