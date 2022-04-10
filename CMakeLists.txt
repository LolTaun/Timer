cmake_minimum_required (VERSION 3.14)

project(Timer)
set(CMAKE_CXX_STANDARD 20)

add_library(Timer STATIC Timer.h Timer.cpp)