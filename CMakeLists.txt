cmake_minimum_required(VERSION 3.10)
project(ServidorP2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(Servidor main.cpp Servidor.cpp Servidor.h)