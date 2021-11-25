cmake_minimum_required(VERSION 3.16)
project(sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(sort main.cpp Select.cpp Select.h Bubble.cpp Bubble.h QuickSort.cpp QuickSort.h HeapSort.cpp HeapSort.h DirectInsert.cpp DirectInsert.h)