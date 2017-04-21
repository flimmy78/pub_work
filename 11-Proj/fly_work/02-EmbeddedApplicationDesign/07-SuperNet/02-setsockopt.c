/*******************************************************************
 *   > File Name: 02-setsockopt.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 02:58:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define N   64      /*缓冲区大小*/
typedef struct sockaddr SA;

/*定义信号处理函数*/
void handler(int signo){
    printf("interrupted by SIGALRM\n");
}

/*-------------------------------------------------------------------
 *定时器超时检测，利用定时器信号SIGALRM，创建一个闹钟。当到达目标时间
 *后，指定的信号处理函数被执行。
 *struct sigaction是linux中用来描述信号行为的结构体类型。
 *100 struct sigaction {                                                                                                           
 *101     __sighandler_t sa_handler;    //信号处理函数
 *102     unsigned long sa_flags;       //信号标志位
 *103 #ifdef SA_RESTORER                
 *104     __sigrestore_t sa_restorer;
 *105 #endif
 *106     sigset_t sa_mask;        //mask last for extensibility掩码
 *107 };
 *------------------------------------------------------------------
 *#include <signal.h>
 *int sigaction(int signum, const struct sigaction *act, 
 *struct sigaction *oldact);                               
 *---------------------------------------------------------------- */
int main(int argc, char* argv[])
{
    int sockfd;
    char buf[N];
    struct sockaddr_in servaddr;
    struct sigaction act;
    
    /* create a UDP_socket */
    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1){
        perror("fail to socket");exit(-1);
    }
    
    /* set the params of the struct sockaddr_in servaddr */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = PF_INET;      //对于BSD,是AF,对于POSIX是PF.
    servaddr.sin_port = htons(9999);
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.170");

    /* bind */
    if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("bind");exit(-1);
    }
    
    /*set the action func for signal*/
    sigaction(SIGALRM, NULL, &act);
    act.sa_handler = handler;
    act.sa_flags &= ~SA_RESTART;
    sigaction(SIGALRM, &act, NULL);

    alarm(6);
    if(recvfrom(sockfd, buf, N, 0, NULL, NULL) < 0){
        perror("fail to recvfrom");exit(-1);
    }
    printf("recv data : %s\n", buf);
    alarm(0);

    return 0;
}
