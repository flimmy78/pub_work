/*******************************************************************
 *   > File Name: 05-getMAC.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Mar 2017 12:00:04 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <net/if.h>
#include <linux/sockios.h>
#include <sys/ioctl.h>

int getMac(const char *in_name, char *MAC, size_t MAC_LEN){
    struct ifreq ifreq;
    int sockfd;
    
        /* 检测输入参数合理性 */
    if(in_name == NULL || strlen(in_name) > 16){
        printf("Invailid arguments\n");return (-1);
    }else if(MAC == NULL || MAC_LEN < 18){
        printf("Invailid arguments\n");return (-2);
    }
        /* 创建套接字 */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");return (-3);
    }
        /* 填充网卡名 */
    strcpy(ifreq.ifr_name, in_name);    /*IFNAMSIZ=16*/
        /* 获取MAC信息 */
    if(ioctl(sockfd, SIOCGIFHWADDR, &ifreq) < 0){
        close(sockfd);
        perror("ioctl");return (-4);
    }
        /* 关闭套接字 */
    if(sockfd > 0)
        close(sockfd);

    int i;
    for(i = 0; i < 6; i++){
        sprintf(MAC + i*3, "%02X:",(unsigned char)ifreq.ifr_hwaddr.sa_data[i]);
        //printf("%02X\n",(unsigned char)ifreq.ifr_hwaddr.sa_data[i]);
    }
    MAC[strlen(MAC) - 1] = '\0';
    //printf("LEN: %d\n",strlen(MAC));
    return (int)NULL;
}

int main(int argc, char* argv[])
{
    char mac[20];

    getMac("eth0", mac, sizeof(mac));
    printf("%s\n",mac);

    return 0;
}
