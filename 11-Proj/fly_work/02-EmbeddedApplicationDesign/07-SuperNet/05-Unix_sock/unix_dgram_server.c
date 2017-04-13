/*******************************************************************
 *   > File Name: unix_dgram_server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 06:36:00 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N   64
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N];
    struct sockaddr_un myaddr, peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    if(argc < 2){
        printf("Usage : <%s> <sock_file>\n", argv[0]);return (-1);
    }

    if((sockfd = socket(PF_UNIX, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }

    remove(argv[1]);
    bzero(&myaddr, sizeof(myaddr));
    myaddr.sun_family = PF_UNIX;
    strcpy(myaddr.sun_path, argv[1]);

    if(bind(sockfd, (SA*)&myaddr, sizeof(myaddr)) < 0){
        perror("fail to bind");exit(-1);
    }

    while(1){
        recvfrom(sockfd, buf, N, 0, (SA*)&peeraddr, &peerlen);
        printf("recvfrom client :%s\n", buf);
        strcpy(buf, "Wecome to Server\n");
        sendto(sockfd, buf, N, 0, (SA*)&peeraddr, peerlen);
    }

    return 0;
}
