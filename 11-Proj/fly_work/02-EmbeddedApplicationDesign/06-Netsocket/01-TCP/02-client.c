/*******************************************************************
 *   > File Name: 02-client.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 10:28:53 AM CST
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
    int sockfd;
    char buf[BUFFER_SIZE] = "Hello Server";
    struct sockaddr_in servaddr;

    if(argc < 3){
        printf("Usage : %s <ip> <port> \n", argv[0]);exit(-1);
    }

    /* 创建socket */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket err");exit(-1);
    }

    /* 设置sockaddr_in结构体中的相关参数 */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /* connect */
    if((connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) == -1){
        perror("connect err");exit(-1);
    }

    /* send massage */
    send(sockfd, buf, sizeof(buf), 0);
    if(recv(sockfd, buf, sizeof(buf), 0)  == -1){
        perror("recv err");exit(-1);
    }

    printf("recv from server :%s\n", buf);
    close(sockfd);

    return 0;
}
