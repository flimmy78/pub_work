/**
  * @file  getmac.c  
  * @brief 常见类型定义
  * @author fly
  * @date     2016-10-28                                                              
  */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>

#include <stdlib.h>

/** 
 * 获取网卡mac地址
 * @param[in]   macaddr		mac数据地址
 * @param[in]   len			数据长度
 * @param[in]   eth_name    网卡名
 * @param[out]  
 * @return        0，执行成功，非0，失败，详见
 * @ref         
 * @see
 * @note
 */ 

int net_getEthNMacAddr(char *macaddr,size_t len,const char *eth_name)
{
	int fd;				/*定义一个套接字描述符*/
	char buffer[20];	/*定义一个字符串buf*/
	struct ifreq ifr;	/*定义一个ifreq结构体*/

	if((fd = socket (AF_INET, SOCK_DGRAM, 0)) >= 0)
	{
		strncpy(ifr.ifr_name, eth_name, IFNAMSIZ);	/*填充网卡名*/
		ifr.ifr_name[IFNAMSIZ - 1] = '\0';
		if((ioctl(fd, SIOCGIFHWADDR, &ifr)) == 0)	/*获取mac信息*/
		{
			snprintf(buffer, 20, "%02x:%02x:%02x:%02x:%02x:%02x",
					(unsigned char)ifr.ifr_hwaddr.sa_data[0],
					(unsigned char)ifr.ifr_hwaddr.sa_data[1],
					(unsigned char)ifr.ifr_hwaddr.sa_data[2],
					(unsigned char)ifr.ifr_hwaddr.sa_data[2],
					(unsigned char)ifr.ifr_hwaddr.sa_data[4],
					(unsigned char)ifr.ifr_hwaddr.sa_data[5]);
		}
		else
		{
			close(fd);
			return -1;/*获取系统mac信息失败*/
		}
	}
	else
	{
		return -1;	/*创建套接字失败*/
	}

	if(strlen(buffer) > len -1)
	{
		close(fd);
		return -1;	/**/
	}

	strncpy(macaddr,buffer,len);

	close(fd);	/*关闭套接字*/

	return 0;
}

#define TEST 1
#if (TEST)
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage : %s  Mac_Name\n",argv[0]);
		exit(EXIT_FAILURE);
	}


	char MAC[20];
	int len = 20;
	char *MAC_Name = argv[1];
	int ret;

    ret = net_getEthNMacAddr(MAC,len,MAC_Name);
	if(ret == -1)
	{
		perror("get mac error !\n");
		return EXIT_FAILURE;
	}
	else
	{
		printf("Local_MAC_Addr : %s \n",MAC);
	}

	exit(EXIT_SUCCESS);
}

#endif
