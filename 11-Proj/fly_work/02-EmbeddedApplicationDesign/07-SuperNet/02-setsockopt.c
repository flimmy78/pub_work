/*******************************************************************
 *   > File Name: 02-setsockopt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 02:58:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define N   64      /*缓冲区大小*/
typedef struct sockaddr SA;

void handler(int signo){
    printf("interrupted by SIGALRM\n");
}

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N];
    struct sockaddr_in servaddr;
    struct sigaction act;

    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = htons(9999);
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.170");

    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("bind");exit(-1);
    }

    sigaction(SIGALRM, NULL, &act);
    act.sa_handler = handler;
    act.sa_flags &= ~SA_RESTART;
    sigaction(SIGALRM, &act, NULL);

    alarm(6);
    if(recvfrom(sockfd, buf, N, 0, NULL, NULL) < 0){
        perror("fail to recvfrom");exit(-1);
    }
    printf("recv data : %s\n", buf);
    alarm(0);

    return 0;
}
