cmake_minimum_required(VERSION 3.22)
project(Data-Structures-and-Algorithm C)

set(CMAKE_C_STANDARD 99)

# Stack Configuration
# add the implementation library
add_subdirectory(stack/implementation)
# add the application library
add_subdirectory(stack/application)

add_executable(Stack-Main stack/main.c)   # add the executable
target_link_libraries(Stack-Main PUBLIC static_stack)
target_link_libraries(Stack-Main PUBLIC dynamic_stack)
target_link_libraries(Stack-Main PUBLIC expression_parser)

# Queue Configuration

# Linked List Configuration
add_subdirectory(linked_list/implementation)

add_executable(LinkedList-Main linked_list/main.c)  # add the executable
target_link_libraries(LinkedList-Main PUBLIC linked_list)
