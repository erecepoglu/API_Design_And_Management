#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    socklen_t addr_size = sizeof(new_addr);
    char buffer[1024];
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    printf("Server socket created successfully.\n");
    memset(&server_addr,'\0',sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(socketfd, (struct sockaddr*)&server_addr,sizeof(server_addr));
    printf("[+]Bind to port number %d.\n",PORT);

    listen(socketfd,5);
    printf("[+]Listening...\n");

    new_socket = accept(socketfd, (struct sockaddr*)&new_addr, &addr_size);
    strcpy(buffer, "Hello");
    send(new_socket, buffer, strlen(buffer),0);
    printf("[+]Closing the connection.\n");
    return 0;
}