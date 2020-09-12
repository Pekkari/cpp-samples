cmake_minimum_required(VERSION 3.5)

add_executable(person main.cpp person.cpp)
target_link_libraries(person PRIVATE libperson)
target_include_directories(person PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_custom_target(run-simple_class ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/person)
