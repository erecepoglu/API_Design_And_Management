#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8801

int main(){
    int socketfd;
    struct sockaddr_in server_addr;

    int new_socket;
    struct sockaddr_in new_addr;

    socklen_t addr_size;
    char buffer[1024];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created successfully.\n");

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(socketfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Bind to port number %d.\n", PORT);

    if (listen(socketfd, 5) < 0) {
        perror("Listen failed");
        close(socketfd);
        exit(EXIT_FAILURE);
    }
    printf("[+]Listening...\n");

    addr_size = sizeof(new_addr);
    new_socket = accept(socketfd, (struct sockaddr*)&new_addr, &addr_size);
    if (new_socket < 0) {
        perror("Accept failed");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    strcpy(buffer, "Hello");
    send(new_socket, buffer, strlen(buffer), 0);

    printf("[+]Closing the connection.\n");
    close(new_socket);
    close(socketfd);

    return 0;
}