/*******************************************************************
 *   > File Name: 02-client.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Apr 2017 01:21:59 PM CST
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
    char buf[BUFFER_SIZE] = "This is a test , from cli !";
    struct sockaddr_in servaddr;

    if(argc < 3){
        printf("Usage :%s <ip> <port> \n", argv[0]);exit(-1);
    }

    /*create a socket*/
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        perror("socket");exit(-1);
    }

    /*set the params of struct sockaddr_in*/
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    /* send massage to server */
    sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    /* recv massage from server */
    if(recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL) < 0){
        perror("recvfrom");exit(-1);
    }

    printf("recv from server :%s\n", buf);
    close(sockfd);

    return 0;
}
