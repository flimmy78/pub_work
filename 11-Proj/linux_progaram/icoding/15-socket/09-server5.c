/*******************************************************************
 *   > File Name: 09-server5.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 25 May 2017 04:11:04 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int result;
    fd_set readfds, testfds;

    /*named a sockfd for server*/
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);

    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    /**/
    listen(server_sockfd, 5);

    FD_ZERO(&readfds);
    FD_SET(server_sockfd, &readfds);

    while(1){
        char ch;
        int fd;
        int nread;

        testfds = readfds;

        printf("server waiting\n");
        //result = select(FD_SETSIZE, &testfds, NULL, NULL, NULL);
        result = select(FD_SETSIZE, &testfds, (fd_set*)0, (fd_set*)0, (struct timeval*)0);

        if(result < 1){
            perror("server5");exit(EXIT_FAILURE);/*出错或超时（0s）*/
        }

        for(fd = 0; fd < FD_SETSIZE; fd ++){
            if(FD_ISSET(fd, &testfds)){
                if(fd == server_sockfd){
                    client_len = sizeof(client_address);
                    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
                    FD_SET(client_sockfd, &readfds);
                    printf("Adding client on fd %d\n", client_sockfd);
                }else{
                    ioctl(fd, FIONREAD, &nread);
                    if(nread == 0){
                        read(fd, &ch, 1);
                        sleep(5);
                        printf("serving client on fd %d\n", fd);
                    }else{
                        read(fd, &ch, 1);
                        sleep(5);
                        printf("serving client on fd %d\n", fd);
                        ch ++;
                        write(fd, &ch, 1);
                    }
                }
            }
        }
    }


    return 0;
}
