#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socketfd;
    struct sockaddr_in serverInfo;
    int addrLen = sizeof(serverInfo);
    char buffer[BUFFER_SIZE] = {0};
    char input[BUFFER_SIZE] = {0};

    // Create socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Fail to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    memset(&serverInfo, 0, addrLen);
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverInfo.sin_port = htons(SERVER_PORT);

    // Get user input
    printf("Enter a message to send to the server: ");
    fgets(input, BUFFER_SIZE, stdin);
    if (input[0] == '\n') {
        exit(EXIT_FAILURE);
    }
    // Remove the newline character from the input
    input[strlen(input) - 1] = '\0';

    // Connect to server
    if (connect(socketfd, (struct sockaddr *)&serverInfo, addrLen) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    send(socketfd, input, strlen(input), 0);

    // Receive message from server
    recv(socketfd, buffer, sizeof(buffer), 0);
    printf("Response: %s\n", buffer);
    close(socketfd);
    return 0;
}