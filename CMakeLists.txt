cmake_minimum_required(VERSION 3.29)
project(Project1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project1 main.cpp
        Project1.h
        outputChart.cpp
        checkKeyword.cpp
        removeSpaces.cpp
        readFile.cpp
        tokenize.cpp
)
