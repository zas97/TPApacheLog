cmake_minimum_required(VERSION 3.8)
project(TPApacheLog)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Log.cpp Parser.cpp LogLine.h)
add_executable(TPApacheLog ${SOURCE_FILES})