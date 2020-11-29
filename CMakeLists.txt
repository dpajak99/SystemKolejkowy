cmake_minimum_required(VERSION 3.17)
project(SystemKolejkowy)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        QueuingSystem.h
        )
set(PROJECT_SOURCES
        main.cpp
        QueuingSystem.cpp
        )

add_executable(SystemKolejkowy ${PROJECT_SOURCES} ${PROJECT_HEADERS})
