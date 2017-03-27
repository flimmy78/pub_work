/*******************************************************************
 *   > File Name: 18-getIP_MAC.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Mar 2017 10:51:08 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>

int main(int argc, char* argv[])
{
    int sock;
    int res;
    struct ifreq ifr;  

    sock = socket(AF_INET, SOCK_STREAM, 0);  
    strcpy(ifr.ifr_name, "eth0");  
    res = ioctl(sock, SIOCGIFADDR, &ifr);  

    //printf("IP: %s\n",inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr));  

    strcpy(ifr.ifr_name, "eth0");  
    res = ioctl(sock, SIOCGIFHWADDR, &ifr);  

    int i;  
    char mac[32];  
    for(i = 0; i < 6; ++i)  
    {  
        sprintf(mac + 3*i, "%02x:", (unsigned char)ifr.ifr_hwaddr.sa_data[i]);  
    }  
    printf("MAC: %s\n",mac);  


    return 0;
}
