#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int new_fd = -1;
	int ret = -1;
	int num = -1;
	char recv_buf[32];
	char kb_buf[32];
	struct sockaddr_in self_addr;

	srv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(srv_fd < 0)
	{
		perror("socket");
		exit(1);
	}	

 	bzero(&self_addr, sizeof(self_addr));
 	self_addr.sin_family = AF_INET;
 	self_addr.sin_port = htons(7890);
	self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if( -1 == bind(srv_fd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
 	{
 		printf("bind: %s\n", strerror(errno));
 	}
	
	listen(srv_fd, 10);

	struct pollfd master[3];
	master[0].fd = 0;
 	master[0].events = POLLIN;
 	
 	master[1].fd = srv_fd;  
 	master[1].events = POLLIN;

 	master[2].fd = -1;
 	master[2].events = POLLIN;
	
	while(1)
	{
 		ret = poll(master, 3, 5000);
		if( 0 == ret)
   			continue;
		if( ret < 0)
		{
   			perror("poll");
			exit(1);
   		}
   		
		if(master[0].revents & POLLIN )
		{
			scanf("%s", kb_buf);
			if( master[2].fd < 0 )
				printf("input from keyborad : %s\n", kb_buf);
			else  /*如果有客户端已经连接，那么就发送客户端*/
			{	
				printf("send to client\n");
				write(master[2].fd, kb_buf, 32);
			}
		}
		if(master[1].revents & POLLIN)
		{
			printf("new connection\n");
			new_fd = accept(srv_fd, NULL,NULL);
			master[2].fd = new_fd;  
			master[2].events = POLLIN;
		}
		/*处理客户端的输入，如果有多个客户，那么可以使用一个循环来判断,当然初始化的时候还要其他处理*/
		if(master[2].revents & POLLIN)
		{
			num = read(new_fd, recv_buf, 32);
			recv_buf[num] = '\0';
			printf("from peer: %s\n", recv_buf);

		}
	} 
  	
	int i ;
	for(i=0; i<3; i++)
		close(master[i].fd);

	return 0;
}
