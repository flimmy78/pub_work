/*******************************************************************
 *   > File Name: 01-setsockopt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 02:18:48 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define SRV_PORT    9999
#define SRV_IP      "192.168.1.170"

#define N   64  /*缓冲区大小*/
typedef struct sockaddr SA;

int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N];
    struct sockaddr_in servaddr;
    struct timeval t = {6, 0};      /*设置时间6秒*/
    
    /* create a  UDP sock */
    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }
    
    /* set the params of struct sockaddr_in for serv */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = htons(SRV_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SRV_IP);
    
    /* bind */
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        perror("bind");exit(-1);
    }
    
    /* set the receive over time for sock*/
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t)) < 0){
        perror("fail to setsockopt");exit(-1);
    }
    /*接收数据前设置了6s的数据超时。
     *如果6s之内无数据包到来，程序会从recvfrom函数返回，进行出错处理
     *设置超时后，每一次发送或接收都会检测；如果要取消超时检测，
     *重新用setsockopt设置，（时间设置为0）
     * */

    if(recvfrom(sockfd, buf, N, 0, NULL, NULL) == -1){
        perror("fail to recvfrom");exit(-1);
    }
    printf("recv data : %s\n", buf);

    return 0;
}
