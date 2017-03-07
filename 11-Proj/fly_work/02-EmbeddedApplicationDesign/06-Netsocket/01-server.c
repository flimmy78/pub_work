/*******************************************************************
 *   > File Name: 01-server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Jan 2017 10:39:41 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 128

int main(int argc, char* argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t peerlen;
    char buf[BUFFER_SIZE];

    if(argc < 3){
        printf("Usage :%s <ip> <port>\n",argv[0]);exit(-1);
    }

    /*建立socket连接*/
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket");exit(-1);
    }

    printf("listenfd = %d\n",listenfd);

    /*设置sockaddr_in结构体*/
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*绑定函数bind()*/
    if(bind(lisenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("bind");exit(-1);
    }

    printf("bind success!\n");

    /*调用listen()函数，设置监听模式*/
    if(listen(listenfd, 10) == -1){
        perror("listen");exit(-1);
    }

    printf("Listening...\n");

    /*调用accept()函数，等待客户端的连接*/
    peerlen = sizeof(cliaddr);
    while(1){
        if((connfd = accept()) < 0)
    }



    return 0;
}
