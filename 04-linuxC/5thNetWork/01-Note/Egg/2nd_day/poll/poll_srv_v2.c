#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <poll.h>
#include <assert.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define N 10
#define IP "192.168.7.11"
#define PORT 7890

int main(int argc, char **argv)
{
	int srv_fd = -1;
	int i = 0;
	int ret = -1;
	int maxcli = -1;
	int num = 0;
	int new_fd = -1;
	ssize_t read_bytes = -1;
	char buf[BUFSIZ];
	bzero(buf, sizeof(buf));

	struct sockaddr_in self;
	
	//socket creat a fd use communcation
	srv_fd = socket(AF_INET, SOCK_STREAM, 0);
	assert(srv_fd > 0);
	
	//set socket_fd address again can use
	int on = 1;
	ret = setsockopt(srv_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));	
	assert(ret == 0);

	//initialized my internet address struct
	memset(&self, 0, sizeof(self));
	
	//give self write data;
	self.sin_family = AF_INET; 
	self.sin_port = htons(PORT);
	self.sin_addr.s_addr = htonl(INADDR_ANY);

	//bind my address peer can send data 
	ret = bind(srv_fd, (struct sockaddr*)&self, sizeof(self));
	assert(ret == 0);
	
	//listen connect accept
	listen(srv_fd, N);

	//poll struct watch define;
	struct pollfd master[N];
	for(i = 0; i < N; i++)
		master[i].fd = -1;

	//watch server socket fd;
	master[0].fd = srv_fd;
	master[0].events = POLLIN;
	num = 1;

	while(1)
	{
		printf(">>poll watch start ...\n");
		ret = poll(master, num, -1);
		if(ret < 0)
		{
			perror("poll");
			exit(1);
		}
		if(master[0].revents & POLLIN)
		{
			printf("new connectiong\n");
			new_fd = accept(srv_fd, NULL, NULL);
			assert(new_fd > 0);

			for(i = 0; i < N; i++)
			{
				if(master[i].fd < 0)
				{

					master[i].fd = new_fd;
					master[i].events = POLLIN;
					if(i > maxcli)
						maxcli = i;
					num ++;
					printf("maxfd = %d, master[%d].fd = %d to be wath\n",  num ++, i, master[i].fd);
					break;
				}
			}

		}

		for(i=1; i<=maxcli; i++)
		{
			if(master[i].revents & POLLIN)
			{
				read_bytes = read(master[i].fd, buf, sizeof(buf));

				if(read_bytes < 0)
					break;
				if(0 == read_bytes)
				{
					printf("client exit\n");
					close(master[i].fd);
					master[i].fd = -1;
					num --;
				}
				printf("receive character string: %s\n", buf);
			}
		}

		printf(">>>end of poll\n");
	}
}
