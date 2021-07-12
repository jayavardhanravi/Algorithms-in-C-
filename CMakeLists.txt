cmake_minimum_required(VERSION 3.21)

project(Algorism)

set(SOURCE Algorism.cpp IAlgorithm.h BinarySearch.h BinarySearch.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})