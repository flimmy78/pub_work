/*******************************************************************
 *   > File Name: tcp_srvT.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 06 Apr 2017 01:55:29 PM CST
 ******************************************************************/

#include <stdio.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define DEFAULT_SRV_IP      "192.168.1.170"
#define DEFAULT_SRV_PORT    9999

typedef struct _tcp_fds{
    int srv_fd;
    int cli_fd;
}tcp_fds, *p_tcp_fds;


#if (0)
int createListenSocket(int port){
    int sock_fd;

    if((sock_fd = create(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");return sock_fd;
    }

    struct sockaddr_in self_addr;
    socklen_t srv_len;

    self_addr.sin_family = AF_INET;
    self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    self_addr.sin_port = htons(port);
    srv_len = sizeof(self_addr);

    if(bind(sock_fd, (const struct sockaddr*)&self_addr, srv_len) != 0){
        perror("bind");return (-1);
    }
}
#endif

p_tcp_fds tcp_srv(p_tcp_fds pfds){
    tcp_fds fds;
    
    /* create a socket */
    if((fds.srv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");return (p_tcp_fds)NULL;
    }

    struct sockaddr_in self_addr, cli_addr;
    socklen_t srv_len, cli_len;
    
    /* name the socket */
    self_addr.sin_family = AF_INET;
    //self_addr.sin_addr.s_addr = inet_addr(DEFAULT_SRV_IP);
    self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //self_addr.sin_port = DEFAULT_SRV_PORT;/*Error*/
    self_addr.sin_port = htons(DEFAULT_SRV_PORT);
    srv_len = sizeof(self_addr);
    
    /* BIND */
    if(bind(fds.srv_fd, (const struct sockaddr*)&self_addr, srv_len) !=0){
        perror("bind");return (p_tcp_fds)NULL;
    }

    /* LISTEN */
    if(listen(fds.srv_fd, 5) != 0){
        perror("listen");return (p_tcp_fds)NULL;
    }
    printf("listening for connect ...\n");

    /* ACCEPT */
    cli_len = sizeof(cli_addr);
    if((fds.cli_fd = accept(fds.srv_fd, (struct sockaddr*)&cli_addr, &cli_len)) < 0){
        perror("accept");return (p_tcp_fds)NULL;
    }
    
    pfds = &fds;

    return pfds;
}

int main(int argc, char* argv[])
{
    p_tcp_fds Pfds = NULL;

    if((Pfds = tcp_srv(Pfds)) == NULL){
        printf("tcp_srv err\n");return (-1);
    }

    printf("---->srv_fd = %d\tcli_fd = %d\n",Pfds->srv_fd, Pfds->cli_fd);
    close(Pfds->srv_fd);
    close(Pfds->cli_fd);

    return 0;
}
