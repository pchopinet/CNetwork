//
// Created by chopinet on 19/04/18.
//

#ifndef LIBNETWORK_TCPSERVER_H
#define LIBNETWORK_TCPSERVER_H


int TCPcreateServer(int port);

int TCPacceptConnection(int socketServer);

void *TCPthreadConnection(void *socketServer);

void TCPserver(int port);


#endif //LIBNETWORK_TCPSERVER_H
