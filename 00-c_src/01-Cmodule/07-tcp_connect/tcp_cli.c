/*******************************************************************
 *   > File Name: tcp_cli.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 06 Apr 2017 03:15:26 PM CST
 ******************************************************************/

#include <stdio.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define DEFAULT_CLI_IP      "192.168.1.170"
#define DEFAULT_CLI_PORT    9999

int tcp_cli(void){
    int cli_fd;
    
    /* create a socket */
    if((cli_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");return cli_fd;
    }
    
    /* named the socket */
    struct sockaddr_in peer_addr;
    int peer_len;

    peer_addr.sin_family = AF_INET;
    peer_addr.sin_addr.s_addr = inet_addr(DEFAULT_CLI_IP);
    peer_addr.sin_port = htons(DEFAULT_CLI_PORT);
    peer_len = sizeof(peer_addr);

    /* CONNECT */
    if((connect(cli_fd, (const struct sockaddr*)&peer_addr, peer_len)) != 0){
        perror("connect");return (-1);
    }

    return cli_fd;
}

int main(int argc, char* argv[])
{
    tcp_cli();
    return 0;
}
