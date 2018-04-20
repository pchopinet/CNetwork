//
// Created by chopinet on 19/04/18.
//

#include "include/TCPserver.h"
#include "include/TCPutil.h"
#include <pthread.h>


int TCPcreateServer(int port) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    bind(sd, (struct sockaddr *) &sa, sizeof(sa));
    listen(sd, SOMAXCONN);

    return sd;

}

int TCPacceptConnection(int socketServer) {
    struct sockaddr_in c_sa;
    int taille = sizeof(c_sa);
    int clientSocket = accept(socketServer, (struct sockaddr *) &c_sa, (socklen_t *) &taille);

    return clientSocket;
}


void *TCPthreadConnection(void *socket) {
    int *socketClient = (int *) socket;
    char *c = TCPrecv(*socketClient);

    printf("Recv : %s\n", c);

    TCPsend(*socketClient, c);

    close(*socketClient);
    free(socketClient);
}

void TCPserver(int port) {
    int serverSocket = TCPcreateServer(port);
    printf("#######################\nServer Socket : %d\n", serverSocket);
    while (1) {
        int *clientSocket = malloc(sizeof(int));
        *clientSocket = TCPacceptConnection(serverSocket);
        pthread_t p;
        if (*clientSocket == -1) exit(-1);
        printf("#######################\nClient Socket : %d\n", *clientSocket);

        pthread_create(&p, NULL, TCPthreadConnection, (void *) clientSocket);
    }
    close(serverSocket);
}
