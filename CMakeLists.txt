cmake_minimum_required(VERSION 3.21)
project(ProjectAED_G24)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectAED_G24 main.cpp src/Airport.cpp src/Airport.h src/Airline.cpp src/Airline.h src/Application.h src/Application.cpp)
