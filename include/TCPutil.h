//
// Created by chopinet on 19/04/18.
//

#ifndef LIBNETWORK_TCPUTIL_H
#define LIBNETWORK_TCPUTIL_H

#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int TCPsend(int socketClient, const char *query);

char *TCPrecv(int socketServer);

char * TCPrecvSimple(int socketClient);

#endif //LIBNETWORK_TCPUTIL_H
