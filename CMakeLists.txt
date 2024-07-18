cmake_minimum_required(VERSION 3.27)
project(activities_register)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)
add_subdirectory(mainApp)

set(SOURCE_FILES
        cppFiles/Activity.cpp
        headerFiles/Activity.h
        cppFiles/Register.cpp
        headerFiles/Register.h
        cppFiles/Date.cpp
        headerFiles/Date.h
        cppFiles/Register.cpp
        headerFiles/Register.h
        cppFiles/Time.cpp
        headerFiles/Time.h)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})