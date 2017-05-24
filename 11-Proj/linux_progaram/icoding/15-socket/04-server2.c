/*******************************************************************
 *   > File Name: 04-server2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 24 May 2017 11:17:46 AM CST
 ******************************************************************/
#if (0)
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    /*create a file descriptor for a socket*/
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /*fulled the address*/
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    
    /*bind a name to a socket*/
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    /*----------------------------------------------------------------*/
    listen(server_sockfd, 5);
    while(1){
        char ch;

        printf("server waiting\n");
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t*)&client_len);

        read(client_sockfd, &ch, 1);
        ch++;
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }

    return 0;
}
