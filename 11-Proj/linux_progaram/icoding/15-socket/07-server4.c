/*******************************************************************
 *   > File Name: 07-server4.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 25 May 2017 02:55:33 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = strlen(&server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    /*创建一个连接队列，忽略子进程的退出细节，等待客户的到来*/
    listen(server_sockfd, 5);

    signal(SIGCHLD, SIG_IGN);

    while(1){
        char ch;

        printf("server waiting\n");

        /*接收连接*/
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);

        /*create new process*/
        if(fork() == 0){
            /*child process to read and write*/
            read(client_sockfd, &ch, 1);
            sleep(5);
            ch ++;
            write(client_sockfd, &ch, 1);
            close(client_sockfd);
            exit(EXIT_FAILURE);
        }else{
            /*parent process to close client_sockfd*/
            close(client_sockfd);
        }
    }

    return 0;
}
