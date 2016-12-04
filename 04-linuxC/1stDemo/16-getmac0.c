#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>

//#define MAX_NET_TYPE 2
#define DEBUG_TEST

#if 0
int get_mac(char *mac, int len_limit, char type)
#else
/*------------------------------------------------------------------------
 *@FUNCTION:获取mac地址,将获取的mac地址以字符串形式填充到mac所指向的内存中
 *@PARAM(IN):mac，字符串指针，
 *@PARAM(IN)：len_limit,mac地址信息字符串的长度
 *@RETURN:成功，返回获得mac字符串的长度；失败，返回-1.
 *-----------------------------------------------------------------------
 */
int get_mac(char *mac, int len_limit)
#endif
{
	struct ifreq ifreq;	/*定义结构体*/
	int sock;			/*定义套接字*/

	/*if(type >= MAX_NET_TYPE || mac == NULL)
		return -1;*/

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)	/*创建套接字*/
	{
		perror("socket");
		return -1;
	}

	strcpy(ifreq.ifr_name,"eth0");	/*填充网卡名*/

	if(ioctl(sock,SIOCGIFHWADDR,&ifreq) < 0)	/*获取mac信息，填充到结构体中*/
	{
		perror("ioctl");
		close(sock);
		return -1;
	}

	close(sock);
	return snprintf(mac,len_limit,"%02X:%02X:%02X:%02X:%02X:%02X",\
			(unsigned char)ifreq.ifr_hwaddr.sa_data[0],\
			(unsigned char)ifreq.ifr_hwaddr.sa_data[1],\
			(unsigned char)ifreq.ifr_hwaddr.sa_data[2],\
			(unsigned char)ifreq.ifr_hwaddr.sa_data[3],\
			(unsigned char)ifreq.ifr_hwaddr.sa_data[4],\
			(unsigned char)ifreq.ifr_hwaddr.sa_data[5]);
}

#ifdef DEBUG_TEST
int main(int argc ,char **argv)
{
	char mac[20];
	int len = 20;
//	int type = 1;

	memset(mac, 0 ,20);

#if 0
	get_mac(mac,len,type);
#else
	get_mac(mac,len);
#endif

	printf("%s\n",mac);

	return 0;
}
#endif
