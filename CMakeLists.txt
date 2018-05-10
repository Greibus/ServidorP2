cmake_minimum_required(VERSION 3.10)
project(ServidorP2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(ServidorP2 ${CMAKE_PROJECT_NAME})

<<<<<<< HEAD
add_executable(Servidor main.cpp Server/Servidor.cpp Server/Servidor.h UserData/User.cpp UserData/User.h MusicManager/Genre.h)
=======

set(SOURCES
        main.cpp
        Servidor.h
        Servidor.cpp
        Trees/BTree.cpp
        Trees/BTree.h
        Trees/BinaryTree.cpp
        Trees/BinaryTree.h
        Sort/QuickSort.cpp
        Sort/QuickSort.h
        Trees/AVLTree.cpp
        Trees/AVLTree.h
        Sort/RadixSort.cpp
        Sort/RadixSort.h
        Sort/BubbleSort.cpp
        Sort/BubbleSort.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
>>>>>>> master
