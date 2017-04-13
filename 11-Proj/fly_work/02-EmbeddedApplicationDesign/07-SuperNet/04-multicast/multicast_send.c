/*******************************************************************
 *   > File Name: multicast_send.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 05:09:25 PM CST
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
    char buf[N] = "This is a multicast package\n";
    struct sockaddr_in dstaddr;

    if(argc < 3){
        printf("Usage : <%s> <ip> <port>\n", argv[0]);return (-1);
    }
    
    /*create a sock of UDP*/
    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }

    /*set the params of IP and port*/
    bzero(&dstaddr, sizeof(dstaddr));
    dstaddr.sin_family = PF_INET;
    dstaddr.sin_port = htons(atoi(argv[2]));
    dstaddr.sin_addr.s_addr = inet_addr(argv[1]);

    while(1){
        /*send data_package*/
        sendto(sockfd, buf, N, 0, (SA*)&dstaddr, sizeof(dstaddr));
        sleep(1);
    }

    return 0;
}
