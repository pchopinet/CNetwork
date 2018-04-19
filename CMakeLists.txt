cmake_minimum_required(VERSION 3.7)
project(Clibnetwork)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/TCPclient.h
        include/TCPserver.h
        include/TCPutil.h
        src/TCPclient.c
        src/TCPserver.c
        src/TCPutil.c
        serv_TP1A_info_tcp.c)

add_executable(Clibnetwork ${SOURCE_FILES})