/*******************************************************************
 *   > File Name: unix_stream_client.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 06:25:08 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N   64
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N] = "Hello Server";
    struct sockaddr_un servaddr;

    if(argc < 2){
        printf("Usage : <%s> <sock_file>\n", argv[0]);return (-1);
    }
    
    /*create a tcp socket*/
    if((sockfd = socket(PF_UNIX, SOCK_STREAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }
    
    /*指定服务器地址（套接字文件）*/
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = PF_UNIX;
    strcpy(servaddr.sun_path, argv[1]);
    
    /*connect*/
    if((connect(sockfd, (SA*)&servaddr, sizeof(servaddr))) < 0){
        perror("fail to connect");exit(-1);
    }
    
    /*send or recv*/
    send(sockfd, buf, N, 0);
    close(sockfd);

    return 0;
}
