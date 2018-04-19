//
// Created by chopinet on 19/04/18.
//

#include "include/TCPclient.h"
#include "include/TCPutil.h"

int TCPconnectServer(const char *IP, int port) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = (in_addr_t) inet_addr(IP);

    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(socketClient, (struct sockaddr *) &sa, sizeof(sa)) != 0) {
        perror("connect : ");
        exit(-1);
    } else {
        printf("Client Socket : %d\n", socketClient);
    }
    return socketClient;
}
