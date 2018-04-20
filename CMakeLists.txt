cmake_minimum_required(VERSION 3.7)
project(Clibnetwork)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

set(SOURCE_FILES
        include/TCPclient.h
        include/TCPserver.h
        include/TCPutil.h
        src/TCPclient.c
        src/TCPserver.c
        src/TCPutil.c
        src/testTCPserver.c src/testTCPclient.c)

add_executable(Clibnetwork ${SOURCE_FILES})