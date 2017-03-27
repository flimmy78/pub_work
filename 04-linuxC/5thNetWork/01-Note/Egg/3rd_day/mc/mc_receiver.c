#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	int rec_fd = -1;
	char recv_buf[32] ;
	int num = -1;
	int ret = -1;	

	rec_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(rec_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	int on = 1;
	ret = setsockopt(rec_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if(ret < 0)
	{
		perror("setsockopt");
		exit(1);
	}
	struct sockaddr_in self_addr;
	struct sockaddr_in peer_addr;
	memset(&self_addr, 0 , sizeof(self_addr));
	memset(&peer_addr, 0 , sizeof(peer_addr));
	self_addr.sin_family = AF_INET;
	self_addr.sin_port = htons(7890);
	self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	ret = bind(rec_fd, (struct sockaddr *)&self_addr, sizeof(self_addr));
	if(ret < 0)
	{
		perror("bind");
		exit(1);
	}
	
	/* add local interface to a multicast address*/
	struct ip_mreq group;
	bzero(&group, sizeof(group));
	group.imr_multiaddr.s_addr = inet_addr("224.100.100.100");
	//group.imr_interface.s_addr = inet_addr(192.168.7.2);
	group.imr_interface.s_addr = htonl(INADDR_ANY);
	
	ret = setsockopt(rec_fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(group));
	if(ret < 0)
	{
		perror("setsockopt");
		exit(1);
	}
	socklen_t peer_len = sizeof(peer_addr);
	while(1)
	{
		num = recvfrom(rec_fd, recv_buf, 32, 0, (struct sockaddr *)&peer_addr, &peer_len);
		if(num < 0)
		{
			perror("recvfrom");
			exit(1);
		}
		recv_buf[num] = '\0';
		printf("recvfrom %s(%d): %s\n", inet_ntoa(peer_addr.sin_addr), 
							ntohs(peer_addr.sin_port), recv_buf );
	}
	close(rec_fd);
	return 0;
}
