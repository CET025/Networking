#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>


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


    for (struct addrinfo *p = servinfo; p != NULL; p = p->ai_next) {
        printf("IP address: %s\n", p->ai_addr->sa_family == AF_INET ? "IPv4" : "IPv6");

        if (getnameinfo(p->ai_addr, p->ai_addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST) == 0) {
            printf("Host: %s\n", host);
        }
        else
        {
            printf("getnameinfo failed\n");
        }

    }

    
    freeaddrinfo(servinfo);

    return 0;
}