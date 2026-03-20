#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv){
    int port = 5000;
    int sockfd;
    struct sockaddr_in my_addr, remote_addr;
    char buffer[1024];
    socklen_t addr_size;
    ssize_t bytes_received;
    char remote_ip[INET_ADDRSTRLEN];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&my_addr, '\0', sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    

    if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(my_addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    addr_size = sizeof(remote_addr);
    bytes_received = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                              (struct sockaddr*)&remote_addr, &addr_size);
    if (bytes_received < 0) {
        perror("recvfrom");
        close(sockfd);
        return 1;
    }

    buffer[bytes_received] = '\0';
    if (inet_ntop(AF_INET, &remote_addr.sin_addr, remote_ip, sizeof(remote_ip)) == NULL) {
        perror("inet_ntop");
        close(sockfd);
        return 1;
    }

    printf("got data '%s' from %s:%d\n", buffer, remote_ip, ntohs(remote_addr.sin_port));

    close(sockfd);
    return 0;

}