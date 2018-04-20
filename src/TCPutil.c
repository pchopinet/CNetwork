//
// Created by chopinet on 19/04/18.
//

#include "include/TCPutil.h"

int TCPsend(int socketClient, const char *query) {
    return (int) send(socketClient, query, strlen(query) + 1, 0);
}

char *TCPrecv(int socketClient) {

    int size = 0;
    char *msg = malloc(sizeof(char));
    do {
        recv(socketClient, msg+size, 1, 0);
        //printf("%c ", msg[size]);
        msg = realloc(msg, sizeof(char) * ++size);
        //printf("%d\n", size);

    } while (msg[size-1] != '\0');
    msg[size - 1] = '\0';

    return msg;
}

int TCPclose(int socket) {
    return close(socket);
}


