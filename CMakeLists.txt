cmake_minimum_required(VERSION 3.23)
project(Codes C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(algorithms)
add_subdirectory(application)
add_subdirectory(data_structures)

add_executable(main main.c)
target_link_libraries(main PUBLIC doubly_circular_ll)
