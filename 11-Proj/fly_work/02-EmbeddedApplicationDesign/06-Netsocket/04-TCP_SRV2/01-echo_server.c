/*******************************************************************
 *   > File Name: 01-echo_server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Apr 2017 10:33:24 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFFER_SIZE     128

int main(int argc, char* argv[])
{
    int listenfd, connfd, n;
    pid_t pid;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t peerlen;
    char buf[BUFFER_SIZE];

    if(argc < 3){
        printf("Usage :%s <ip> <port>\n", argv[0]);exit(-1);
    }

    /*create a socket*/
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket");exit(-1);
    }

    /*set the params of struct sockaddr_in*/
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*bind*/
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        perror("bind");exit(-2);
    }

    /*listen*/
    if(listen(listenfd, 10) == -1){
        perror("listen");exit(-3);
    }

    /*ignore the signal of SIGCHLD*/
    signal(SIGCHLD, SIG_IGN);

    peerlen = sizeof(cliaddr);
    while(1){
        if((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &peerlen)) == -1){
            perror("connfd");exit(-1);
        }

        printf("connection from [%s:%d]\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        if((pid = fork()) < 0){
            perror("fork");exit(-1);
        }else if(pid == 0){
            while((n = recv(connfd, buf, BUFFER_SIZE, 0)) > 0){
                printf("echo : %s",buf);
                send(connfd, buf, n, 0);
                exit(-1);
            }
            printf("client is closed\n");exit(0);
        }else{
            close(connfd);
        }
    }

    close(listenfd);

    return 0;
}
