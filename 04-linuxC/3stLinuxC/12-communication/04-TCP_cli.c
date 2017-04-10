/*******************************************************************
 *   > File Name: 04-TCP_cli.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 03:32:34 PM CST
 ******************************************************************/
#if (0)
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
ssize_t recv(int sockfd, void *buf, size_t len, int flags);

struct sockaddr{
    sa_family_t sa_family;
    char sa_data[14];
};

struct sockaddr_in{
    unsigned short int sin_family;
    uint16_t sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};

struct in_addr{
    uint32_t s_addr;
};
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define PORT        1024
#define SERVER_IP   "127.0.0.1"

int main(int argc, char* argv[])
{
    int s;
    struct sockaddr_in addr;
    char buffer[256];
    
    /*create a socket*/
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");exit(-1);
    }

    /*set the params of the struct sockaddr_in*/
    bzero(&addr, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);

#if (0)
    if((bind(s, (struct sockaddr*)&addr, sizeof(addr))) == -1){
        perror("bind");exit(-2);
    }
#endif
    
    /*connect*/
    if((connect(s, (struct sockaddr*)&addr, sizeof(addr))) == -1){
        perror("connect");exit(-3);
    }
    
    /*recv massage from socket*/
    recv(s, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    while(1){
        bzero(buffer, sizeof(buffer));
        /*read massage from stdin*/
        read(STDIN_FILENO, buffer, sizeof(buffer));
        
        /*send massage to socket*/
        if(send(s, buffer, sizeof(buffer), 0) < 0){
            perror("send");exit(1);
        }
    }

    return 0;
}
