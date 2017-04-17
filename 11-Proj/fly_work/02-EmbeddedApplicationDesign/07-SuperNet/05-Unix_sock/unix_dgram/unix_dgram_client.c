/*******************************************************************
 *   > File Name: unix_dgram_client.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 06:51:35 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N       64
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N] = "Hello Server";
    struct sockaddr_un servaddr, myaddr;
    
    if(argc < 2){
        printf("Usage : <%s> <sock_file>\n", argv[0]);return (-1);
    }
    
    /*create a UDP socket*/
    if((sockfd = socket(PF_UNIX, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = PF_UNIX;
    strcpy(servaddr.sun_path, argv[1]);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = PF_UNIX;
    strcpy(servaddr.sun_path, "sock_client");

    remove("sock_client");

    /*bind*/
    if((bind(sockfd, (SA*)&myaddr, sizeof(myaddr))) < 0){
        perror("bind");exit(-1);
    }

    sendto(sockfd, buf, N, 0, (SA*)&servaddr, sizeof(servaddr));
    recvfrom(sockfd, buf, N, 0, NULL, NULL);
    printf("recvfrom server :%s\n", buf);
    close(sockfd);

    return 0;
}
