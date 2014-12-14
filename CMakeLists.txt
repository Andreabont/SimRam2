cmake_minimum_required(VERSION 2.6)
project(simram)

add_executable(simram main.cpp)

install(TARGETS simram RUNTIME DESTINATION bin)
