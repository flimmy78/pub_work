/*******************************************************************
 *   > File Name: unix_stream_server.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 05:53:57 PM CST
 ******************************************************************/
#if (0)
struct sockaddr_un
{
    unsigned short sun_family;  /*Protocol type*/
    char sun_path[108];         /*Path name*/
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 64
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int listenfd, connfd;
    char buf[N];
    struct sockaddr_un myaddr;

    if(argc < 2){
        printf("Usage : <%s> <sock_file>\n", argv[0]);return (-1);
    }
    
    /*create a TCP socket*/
    if((listenfd = socket(PF_UNIX, SOCK_STREAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }

    remove(argv[1]);    /*删除套接字文件*/
    bzero(&myaddr, sizeof(myaddr));
    myaddr.sun_family = PF_UNIX;
    strcpy(myaddr.sun_path, argv[1]);
    
    /*bind*/
    if((bind(listenfd, (SA*)&myaddr, sizeof(myaddr))) == -1){
        perror("fail to bind");return (-1);
    }

    /*listen*/
    if((listen(listenfd, 10)) == -1){
        perror("listen");return (-1);
    }

    while(1){
        /*accept*/
        if((connfd = accept(listenfd, NULL, NULL)) < 0){
            perror("fail to accept");exit(-1);
        }
    
        /*recv or sned*/
        recv(connfd, buf, N, 0);
        printf("recv from client : %s\n", buf);
        close(connfd);
    }

    return 0;
}
