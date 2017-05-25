/*******************************************************************
 *   > File Name: 06-getdate.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 25 May 2017 01:49:36 PM CST
 ******************************************************************/
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *host;
    int sockfd;
    int len, result;
    struct sockaddr_in address;
    struct hostent *hostinfo;
    struct servent *servinfo;
    char buffer[128];
    
    /*获取主机名*/
    if(argc == 1){
        host = "localhost";
    }else{
        host = argv[1];
    }
    
    /*查找主机地址*/
    hostinfo = gethostbyname(host);
    if(!hostinfo){
        fprintf(stderr, "no host :%s\n", host);exit(EXIT_FAILURE);
    }

   // printf("official name of host :%s\nhost address type : %d\nlength of address :%d\n",\
   //         hostinfo -> h_name,\
   //         hostinfo -> h_addrtype,\
   //         hostinfo -> h_length);
    /*检查主机上是否有daytime服务*/
    servinfo = getservbyname("daytime", "tcp");
    if(!servinfo){
        fprintf(stderr, "No daytime service\n");
        exit(1);
    }
    printf("daytime port is %d\n", ntohs(servinfo -> s_port));

    /*创建一个套接字*/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /*构造connect调用要使用的地址*/
    address.sin_family = AF_INET;
    address.sin_port = servinfo -> s_port;
    address.sin_addr = *(struct in_addr *)*hostinfo -> h_addr_list;
    len = sizeof(address);

    /*建立连接并取得有关信息*/
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1){
        perror("oops :getdate");exit(EXIT_FAILURE);
    }

    result = read(sockfd, buffer, sizeof(buffer));
    buffer[result] = '\0';
    printf("read %d bytes :%s", result, buffer);
    close(sockfd);

    return 0;
}
