/*******************************************************************
 *   > File Name: 01-server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 09 Apr 2017 10:46:56 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE     128

int main(int argc, char* argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t peerlen;
    char buf[BUFFER_SIZE];

    if(argc  < 3){
        printf("Usage : %s <ip> <port> \n",argv[0]);exit(-1);
    }

    /*建立socket连接*/
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket err");exit(-1);
    }

    printf("listenfd = %d\n",listenfd);

    /*设置sockaddr_in结构体相关参数*/
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*绑定函数bind（）*/
    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("bind err");exit(-1);
    }
    printf("bind success!\n");

    /*调用listen（）函数，设置监听模式*/
    if(listen(listenfd, 10) == -1){
        perror("listen err");exit(-1);
    }
    printf("Listening...\n");

    /*调用accept（）函数，等待客户端的连接*/
    peerlen = sizeof(cliaddr);
    while(1){
        if((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &peerlen)) < 0){
            perror("accept err");exit(-1);
        }

        /*调用recv（）函数接收客户端发送的数据*/
        memset(buf, 0, sizeof(buf));
        if(recv(connfd, buf, BUFFER_SIZE, 0) == -1){
            perror("recv err");exit(-1);
        }
        printf("Received a message from cli:%s\n", buf);

        strcpy(buf, "Welcome to server");
        send(connfd, buf, BUFFER_SIZE, 0);
        close(connfd);
    }

    close(listenfd);
    return 0;
}
