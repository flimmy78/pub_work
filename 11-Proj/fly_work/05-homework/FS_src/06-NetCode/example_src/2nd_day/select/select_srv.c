#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 #include <assert.h>
#include <unistd.h>

#define LEN 128

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int new_fd = -1;
	int ret = -1;
	int num = -1;
	char recv_buf[LEN];
	char kb_buf[LEN];
	struct sockaddr_in self;
	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);

	srv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(srv_fd < 0 )
	{
		perror("socket");
		exit(1);
	}
	int on = 1;
	setsockopt(srv_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	bzero(&cli, sizeof(cli));
	bzero(&self, sizeof(self));
	self.sin_family = AF_INET;
	self.sin_port = htons(7890);
	self.sin_addr.s_addr = inet_addr("192.168.7.100");
	ret = bind(srv_fd,  (struct sockaddr *)&self, sizeof(self));	
	if(ret < 0)
	{
		perror("bind");
		exit(1);
	}
	
	listen(srv_fd, 5);


/**********************************************/
	/* step1: create a fd_set*/
	fd_set rd_set;
	int maxfd = srv_fd;

	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 100;

	while(1)
	{
		// init
		FD_ZERO(&rd_set);
		// set all fd that we want to monitor to rd_set
		FD_SET(srv_fd, &rd_set);
		FD_SET(new_fd, &rd_set); //first time, new_fd == -1;
		FD_SET(0, &rd_set);  // set std input to rd_set;

		//select(maxfd+1, rd_set, NULL, NULL, &timeout);
		ret = select(maxfd+1, &rd_set, NULL, NULL, NULL);
		//assert(ret > 0);
		if(ret < 0)
		{
			perror("select");
			exit(1);
		}
		if(FD_ISSET(0, &rd_set))
		{
			fgets(kb_buf, LEN, stdin);
			if(new_fd > 0)
				write(new_fd, kb_buf, strlen(kb_buf));
			else
				printf("kb_buf = %s\n", kb_buf);
		}
		if(FD_ISSET(srv_fd, &rd_set))
		{
			printf("new connect from client\n");
			new_fd = accept(srv_fd, (struct sockaddr *)&cli, &len);
			assert(new_fd > 0);
			if(new_fd > maxfd)
				maxfd = new_fd;

			printf("new_fd = %d ,client is : %s, port = %d\n", 
					new_fd, inet_ntoa(cli.sin_addr),  ntohs(cli.sin_port));
		}
		if(FD_ISSET(new_fd, &rd_set))
		{
			num = read(new_fd, recv_buf, LEN);
			if(num < 0)
			{
				perror("read");
				exit(1);
			}
			if(num == 0)
			{
				close(new_fd);
				new_fd = -1;
				continue;
			}
			recv_buf[num] = '\0';
			printf("%d, recv buf = %s\n", new_fd , recv_buf);
		}
		
	}



	close(new_fd);
	close(srv_fd);

	
	return 0;
}
