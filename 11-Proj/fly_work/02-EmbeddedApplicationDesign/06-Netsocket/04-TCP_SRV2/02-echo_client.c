/*******************************************************************
 *   > File Name: 02-echo_client.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Apr 2017 01:23:05 PM CST
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
    char buf[BUFFER_SIZE];
    struct sockaddr_in servaddr;

    if(argc < 3){
        printf("Usage :%s <ip> <port>\n", argv[0]);exit(-1);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket");exit(-1);
    }

    /* set the params of struct sockaddr_in */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*connect*/
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        perror("connect");exit(-1);
    }

    while(1){
        printf("input >");
        fgets(buf, BUFFER_SIZE, stdin);
        if(strcmp(buf, "quit\n") == 0)
            break;
        send(sockfd, buf, BUFFER_SIZE, 0);
        bzero(buf, BUFFER_SIZE);
        recv(sockfd, buf, BUFFER_SIZE, 0);
        printf("recv from server :%s\n", buf);
    }
    printf("client is quit\n");
    close(sockfd);

    return 0;
}
