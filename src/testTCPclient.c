//
// Created by chopinet on 20/04/18.
//

#include <include/TCPclient.h>
#include <include/TCPutil.h>

int main(int argc, char *argv[]) {
    int socket = TCPconnectServer(argv[1], atoi(argv[2]));
    printf("TCPsend : %d\n",TCPsend(socket,"ui"));
    printf("TCPrcv : %s\n", TCPrecv(socket));
    close(socket);
}