cmake_minimum_required(VERSION 3.22)
project(Codes C)

set(CMAKE_C_STANDARD 99)

add_executable(Codes main.c)

# LinkedList
add_executable(LinkedList-Implementation LinkedList/Implementation.c)

# Stacks
add_executable(StacksDynamicArrays Stack/ImplementationUsingDynamicArrays.c)
add_executable(StacksStaticArrays Stack/ImplementationUsingStaticArray.c)
add_executable(StackAppBalancedParenthesis Stack/Application/BalancedParenthesis.c)
add_executable(StackAppExpressionChanger Stack/Application/ExpressionChanger.c)
add_executable(StackAppExpressionEval Stack/Application/ExpressionEvaluator.c)



