#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socketfd, clientSocketfd;
    struct sockaddr_in serverInfo;
    int addrLen = sizeof(serverInfo);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Fail to create socket");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    memset(&serverInfo, 0, addrLen);
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverInfo.sin_port = htons(PORT);

    if (bind(socketfd, (struct sockaddr *)&serverInfo, addrLen) < 0) {
        perror("Fail to bind");
        exit(EXIT_FAILURE);
    }
    if (listen(socketfd, 3) < 0) {
        perror("Fail to listen");
        exit(EXIT_FAILURE);
    }
    printf("Server is running...\n");
    while (1) {
        // reset buffer
        memset(buffer, 0, sizeof(buffer));
        // Accept connection from client
        if ((clientSocketfd = accept(socketfd, (struct sockaddr *)&serverInfo, (socklen_t*)&addrLen)) < 0) {
            perror("Fail to accept");
            continue;
        }
        // Receive data from the client
        if (recv(clientSocketfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Fail to recieve");
            continue;
        }
        printf("Received: %s\n", buffer);
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        if (send(clientSocketfd, buffer, strlen(buffer), 0) < 0) {
            perror("Fail to send");
        }
        close(clientSocketfd);
    }
    return 0;
}