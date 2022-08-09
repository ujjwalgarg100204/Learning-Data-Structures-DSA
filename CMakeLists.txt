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
target_link_libraries(Stack-Main PUBLIC linked_stack)
target_link_libraries(Stack-Main PUBLIC expression_parser)
target_link_libraries(Stack-Main PUBLIC small_applications_stack)

# Queue Configuration
add_subdirectory(queue/implementation)

add_executable(Queue-Main queue/main.c)
target_link_libraries(Queue-Main PUBLIC circular_static_queue)
target_link_libraries(Queue-Main PUBLIC static_queue)

# Linked List Configuration
add_subdirectory(linked_list/implementation)

add_executable(LinkedList-Main linked_list/main.c)  # add the executable
target_link_libraries(LinkedList-Main PUBLIC linked_list)

# Dynamic Array Configuration
add_subdirectory(dynamic_array/implementation)

add_executable(DynamicArray-Main dynamic_array/main.c)  # add the executable
target_link_libraries(DynamicArray-Main PUBLIC dynamic_array_using_static_array)
target_link_libraries(DynamicArray-Main PUBLIC dynamic_array)

