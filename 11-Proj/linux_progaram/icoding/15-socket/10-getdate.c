/*******************************************************************
 *   > File Name: 10-getdate.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 25 May 2017 05:31:56 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *host;
    int sockfd;
    int len, result;
    struct sockaddr_in address;
    struct hostent *hostinfo;
    struct servent *servinfo;
    char buffer[128];

    if(argc == 1){
        host = "localhost";
    }else{
        host = argv[1];
    }

    hostinfo = gethostbyname(host);
    if(!hostinfo){
        fprintf(stderr, "no host :%s\n", host);exit(EXIT_FAILURE);
    }

    servinfo = getservbyname("daytime", "udp");
    if(!servinfo){
        fprintf(stderr, "No daytime service\n");exit(EXIT_FAILURE);
    }
    printf("daytime port is %d\n", ntohs(servinfo -> s_port));

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    address.sin_family = AF_INET;
    address.sin_port = servinfo -> s_port;
    address.sin_addr = *(struct in_addr *)*hostinfo -> h_addr_list;
    len = sizeof(address);

    result = sendto(sockfd, buffer, 1, 0, (struct sockaddr *)&address, len);
    result = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&address, &len);
    buffer[result] = '\0';

    printf("read %d bytes: %s", result, buffer);

    close(sockfd);

    return 0;
}
