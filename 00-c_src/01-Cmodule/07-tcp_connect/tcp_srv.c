/*******************************************************************
 *   > File Name: tcp_srv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 05 Apr 2017 04:28:56 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

#define DEFAULT_SRV_IP      "192.168.1.170"
#define DEFAULT_SRV_PORT    9999

static int srv_fd, cli_fd;

int create_tcp_srv(void){
    int res;
    char BUF[128];

    /*create  a srv_sockfd*/
    if((srv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("create a srv_sockfd err");return (-1);
    }
    
    /*padding the srv_addr*/
    struct sockaddr_in self_addr;
    self_addr.sin_family = AF_INET;
    self_addr.sin_port = htons(DEFAULT_SRV_PORT);
    self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    socklen_t self_addr_len = sizeof self_addr;
    
    /*BIND*/
    if((res = bind(srv_fd,(const struct sockaddr*)self_addr, self_addr_len)) != 0){
        perror("bind the addr err");return (-2);
    }
    
    /*LISTEN*/
    if((res = listen(srv_fd, 5)) != 0){
        perror("listen");return res;
    }
    printf("listening for connect...\n");
    
    /*ACCEPT*/
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    if((cli_fd = accept(srv_fd, &cli_addr, &cli_len)) < 0){
        perror("accept\n");return cli_fd;
    }

    printf("client ip : %s, port : %d\n",inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    return cli_fd;
}

int main(int argc, char* argv[])
{
    return 0;
}
