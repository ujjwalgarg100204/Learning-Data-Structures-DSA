cmake_minimum_required(VERSION 3.22)
project(Codes C)

set(CMAKE_C_STANDARD 99)

add_executable(Codes main.c)

# LinkedList
add_executable(LinkedList-Implementation LinkedList/Implementation.c)

# Stacks
add_executable(Stacks Stack/ImplementationUsingDynamicArrays.c)
add_executable(StackAppBalancedParenthesis Stack/Application/BalancedParenthesis.c)



