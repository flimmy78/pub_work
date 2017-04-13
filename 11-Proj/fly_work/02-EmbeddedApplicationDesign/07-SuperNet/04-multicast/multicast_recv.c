/*******************************************************************
 *   > File Name: multicast_recv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 05:26:00 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define N   64
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N];
    struct ip_mreq mreq;
    struct sockaddr_in myaddr, peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    if(argc < 3){
        printf("Usage : <%s> <ip> <port>\n", argv[0]);return (-1);
    }

    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        perror("socket");return (-1);
    }

    /*加入多播组，允许数据链路层处理指定组播包*/
    bzero(&mreq, sizeof(mreq));
    mreq.imr_multiaddr.s_addr = inet_addr(argv[1]);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if((setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq))) < 0){
        perror("fail to setsockopt");exit(-1);
    }

    bzero(&myaddr, sizeof(myaddr));
    myaddr.sin_family = PF_INET;
    myaddr.sin_port = htons(atoi(argv[2]));
    myaddr.sin_addr.s_addr = inet_addr(argv[1]);

    if((bind(sockfd, (SA*)&myaddr, sizeof(myaddr))) == -1){
        perror("bind");exit(-1);
    }

    while(1){
        recvfrom(sockfd, buf, N, 0, (SA*)&peeraddr, &peerlen);
        printf("[%s : %d] %s\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port), buf);
    }

    return 0;
}
