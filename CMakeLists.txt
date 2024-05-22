cmake_minimum_required(VERSION 3.27)
project(activities_register)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Activity.cpp Activity.h
        Register.cpp
        Register.h
        Date.cpp
        Date.h
        Register.cpp
        Register.h
        Time.cpp
        Time.h)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)