cmake_minimum_required(VERSION 3.10)
project(ServidorP2)

find_path(RapidXML_INCLUDE_DIR rapidxml.hpp PATH_SUFFIXES rapidxml)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(ServidorP2 ${CMAKE_PROJECT_NAME})
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(RapidXML DEFAULT_MSG RapidXML_INCLUDE_DIR)
mark_as_advanced(RapidXML_INCLUDE_DIR)

if(RAPIDXML_FOUND)
    # provide import target:
    add_library(RapidXML::RapidXML INTERFACE IMPORTED Sort/QuickSortA.cpp Sort/QuickSortA.h)
    set_target_properties(RapidXML::RapidXML PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${RapidXML_INCLUDE_DIR})
endif()

#Para que busque la libreria de limmpg123, solo se corre una vez y listo
FIND_PATH( MPG123_INCLUDE_DIR1
        NAMES mpg123.h
        PATH_SUFFIXES include
        PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        extern/mpg123/ports/MSVC++
        extern/mpg123/ports/Xcode
        )

IF( MPG123_INCLUDE_DIR1 )
    SET( MPG123_INCLUDE_DIRS ${MPG123_INCLUDE_DIRS} ${MPG123_INCLUDE_DIR1} )
ENDIF( MPG123_INCLUDE_DIR1 )

# Include dir (May not be necessary on all platforms)
FIND_PATH( MPG123_INCLUDE_DIR2
        NAMES mpg123.h.in
        PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        extern/mpg123/src/libmpg123
        )

IF( MPG123_INCLUDE_DIR2 )
    SET( MPG123_INCLUDE_DIRS ${MPG123_INCLUDE_DIRS} ${MPG123_INCLUDE_DIR2} )
ENDIF( MPG123_INCLUDE_DIR2 )

#MESSAGE( "MPG123_INCLUDE_DIR1: " ${MPG123_INCLUDE_DIR1} )
#MESSAGE( "MPG123_INCLUDE_DIR2: " ${MPG123_INCLUDE_DIR2} )
#MESSAGE( "MPG123_INCLUDE_DIRS: " ${MPG123_INCLUDE_DIRS} )

FIND_LIBRARY( MPG123_LIBRARIES
        NAMES mpg123 libmpg123.lib
        HINTS
        PATH_SUFFIXES lib64 lib libs64 libs libs/Win32 libs/Win64 Release Debug
        PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw
        /opt/local
        /opt/csw
        /opt
        extern/mpg123/ports/MSVC++/2005
        extern/mpg123/ports/MSVC++/2008
        extern/mpg123/ports/MSVC++/2008clr
        extern/mpg123/ports/MSVC++/2010
        )

SET( MPG123_FOUND 0 )
IF( MPG123_LIBRARIES AND MPG123_INCLUDE_DIRS )
    SET( MPG123_FOUND 1 )
    MESSAGE( STATUS "mpg123 found!" )
ELSE( MPG123_LIBRARIES AND MPG123_INCLUDE_DIRS )
    MESSAGE( STATUS "mpg123 not found..." )
ENDIF( MPG123_LIBRARIES AND MPG123_INCLUDE_DIRS )

set(SOURCES
        main.cpp
        Server/Servidor.cpp
        Server/Servidor.h
        UserData/User.cpp
        UserData/User.h
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
        Json/SaveJson.cpp
        Json/SaveJson.h
        MusicManager/Song.cpp
        MusicManager/Song.h
        MusicManager/Decoder.cpp
        MusicManager/Decoder.h
        MusicManager/MusicManager.h
        MusicManager/MusicManager.cpp
        UserData/Hash.cpp
        UserData/Hash.h
        Sort/QuickSortA.cpp
        Sort/QuickSortA.h
        )


#Se conecta con la libreria de mpg123
include_directories(${MPG123_INCLUDE_DIRS})
link_directories(${MPG123_LIBRARY_DIRS})

#
#link_directories(/usr/local/lib/libb64.a)
#link_directories(/usr/local/include/b64)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

#link librerias libmpg123
TARGET_LINK_LIBRARIES(ServidorP2 ${MPG123_LIBRARIES})

#TARGET_LINK_LIBRARIES(ServidorP2 /usr/local/lib/libb64.a)