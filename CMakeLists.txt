cmake_minimum_required(VERSION 3.10)
project(ServidorP2)

find_path(RapidXML_INCLUDE_DIR rapidxml.hpp PATH_SUFFIXES rapidxml)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(ServidorP2Copia ${CMAKE_PROJECT_NAME})
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(RapidXML DEFAULT_MSG RapidXML_INCLUDE_DIR)
mark_as_advanced(RapidXML_INCLUDE_DIR)

if(RAPIDXML_FOUND)
    # provide import target:
    add_library(RapidXML::RapidXML INTERFACE IMPORTED)
    set_target_properties(RapidXML::RapidXML PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${RapidXML_INCLUDE_DIR})
endif()


set(SOURCES
        main.cpp
        Server/Servidor.cpp
        Server/Servidor.h
        UserData/User.cpp
        UserData/User.h
        MusicManager/Genre.h
        Trees/LinkedList.cpp
        Trees/LinkedList.h
        Trees/LLNode.cpp
        Trees/LLNode.h
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
        Sort/BubbleSort.h
        UserData/LinkedListUser.cpp
        UserData/LinkedListUser.h
        UserData/NodeUser.cpp
        UserData/NodeUser.h
        Json/SaveJson.cpp Json/SaveJson.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
