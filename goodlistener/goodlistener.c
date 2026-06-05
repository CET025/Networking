#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>


int main() {
    int result;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    char host[NI_MAXHOST];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    result = getaddrinfo("localhost", "8080", &hints, &servinfo);
    if (result != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        return 1;
    }

    int socketfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (socketfd == -1) {
        perror("socket");
        return 1;
    };

    int bind_result = bind(socketfd, servinfo->ai_addr, servinfo->ai_addrlen);
    if (bind_result == -1) {
        perror("bind");
        return 1;
    };

    printf("Binded to socket %d\n", socketfd);

    while (1) {
        int listen_result = listen(socketfd, 5);
        if (listen_result == -1) {
            perror("listen");
            return 1;
        };
        printf("Listening on socket %d ...\n", socketfd);

        struct sockaddr_storage client_addr; 
        socklen_t addr_size = sizeof(client_addr);
        int new_fd = accept(socketfd, (struct sockaddr *)&client_addr, &addr_size);
        if (new_fd == -1) {
            perror("accept");
            return 1;
        };
        printf("Accepted connection on socket %d\n", new_fd);

        sleep(1);

    };

        


    
    freeaddrinfo(servinfo);

    return 0;
}