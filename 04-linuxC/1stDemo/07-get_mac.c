#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define DEBUG_TEST

/**********************************************************
  *
  ********************************************************/
int get_mac(char *macaddr, size_t len, const char *eth_name)
{
	int sock_fd;
	char buffer[20];
	struct ifreq ifr;

	if(sock_fd = socket(AF_INET, SOCK_DGRAM, 0) >= 0)/*创建一个数据报套接字*/ 
	{
		strncpy(ifr.ifr_name, eth_name,IFNAMSIZ );	/*填充网卡名*/
		ifr.ifr_name[IFNAMSIZ - 1] = '\0';
		if((ioctl(sock_fd, SIOCGIFHWADDR, &ifr)) == 0)
		{
			snprintf(buffer,20,"%02x:%02x:%02x:%02x:%02x:%02x",
					(unsigned char)ifr.ifr_hwaddr.sa_data[0],
					(unsigned char)ifr.ifr_hwaddr.sa_data[1],
					(unsigned char)ifr.ifr_hwaddr.sa_data[2],
					(unsigned char)ifr.ifr_hwaddr.sa_data[3],
					(unsigned char)ifr.ifr_hwaddr.sa_data[4],
					(unsigned char)ifr.ifr_hwaddr.sa_data[5]);
		}
		else
		{
			close(sock_fd);
			return (-1);
		}
	}
	else
	{
		return (-1);
	}
	
	if(strlen(buffer) > len - 1)
	{
		return (-1);
	}
	strncpy(macaddr,buffer,len);
	
	close(sock_fd);
	
	return 0;
}

#ifdef DEBUG_TEST
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage :%s mac_name\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	
    char MAC[20];
	int len = 20;
	char *mac_name = argv[1];
	int ret;

	ret = get_mac(MAC, len , mac_name);
	if(ret == -1)
	{
		printf("get_mac err \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("MAC : %s\n",MAC);
	}

	exit(EXIT_SUCCESS);
}
#endif
