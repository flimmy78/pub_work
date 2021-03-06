/*******************************************************************
 *   > File Name: broadcast_send.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 03:26:44 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define N   64
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N] = "This is a broadcast package\n";
    int on = 1;
    struct sockaddr_in dstaddr;

    if(argc < 3){
        printf("Usage : <%s>  <ip>  <port>\n", argv[0]);return (-1);
    }
    
    /*create a UDP socket*/
    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }
    
    /*set the params of struct sockaddr_in*/
    bzero(&dstaddr, sizeof(dstaddr));
    dstaddr.sin_family = PF_INET;
    dstaddr.sin_port = htons(atoi(argv[2]));
    dstaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*set the socket options, allow broadcast packets*/
    if(setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0){
        perror("fail to setsockopt");exit(-1);
    }

    while(1){
        /*set data pakeages*/
        sendto(sockfd, buf, N, 0, (SA*)&dstaddr, sizeof(dstaddr));
        sleep(1);
    }

    return 0;
}
