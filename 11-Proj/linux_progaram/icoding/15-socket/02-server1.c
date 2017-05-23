/*******************************************************************
 *   > File Name: 02-server1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue May 23 15:03:15 2017
 ******************************************************************/
#if (0)
int unlink(const char *pathname);
int socket(int domain, int type, int protocol);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen(int sockfd, int backlog);
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    unlink("server_socket");
    
    /*create the file descriptor sockfd*/
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    server_address.sun_family = AF_UNIX;    /*Local communication*/
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);

    /*bind*/
    bind(server_sockfd, (const struct sockaddr *)&server_address, server_len);

    /*listen*/
    listen(server_sockfd, 5);

    while(1){
        char ch;
        printf("server waiting\n");

        client_len = sizeof(client_address);
        /*accept*/
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);
        printf("We got a client request ,");

        /*read*/
        read(client_sockfd, &ch, 1);
        printf("receive %c .\n", ch);
        ch++;
        /*write*/
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }

    return 0;
}
