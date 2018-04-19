//
// Created by chopinet on 19/04/18.
//

#include "include/TCPutil.h"

int TCPsend(int socketClient, const char *query) {
    return (int) send(socketClient, query, strlen(query) + 1, 0);
}

char *TCPrecv(int socketClient) {

    if (socketClient == -1) {
        return "-1";
    }

    int size = 1;
    char *msg = malloc(sizeof(char));
    char c;

    do {

        recv(socketClient, &c, 1, 0);
        msg[size - 1] = c;
        msg = realloc(msg, sizeof(char) * ++size);

    } while (c != '\0');

    return msg;
}


