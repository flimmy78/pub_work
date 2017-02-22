#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>

#define BYTES_NUM   100

int main(int argc , char *argv[])
{
	int srv_fd = -1;
	int ret = -1;
	
	struct sockaddr_in srv_addr;
	struct sockaddr_in peer_addr;
	
	srv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == srv_fd)
	{
		printf("socket create : %s\n", strerror(errno));
		exit(-1);
	}
	memset(&peer_addr, 0, sizeof(struct sockaddr_in));
	memset(&srv_addr, 0, sizeof(struct sockaddr_in));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr  = htonl(INADDR_ANY);
	srv_addr.sin_port = htons(7890);
	if ( -1 == bind(srv_fd, (struct sockaddr *)&srv_addr, sizeof(struct sockaddr_in)))
	{				
		printf("bind: %s\n", strerror(errno));
		exit(-1);
	}

	listen(srv_fd, 10);

	/*
		step1: create a fd_set; 
	*/
	fd_set rd_set;
	/*for out of band data*/
	fd_set exp_set;

	int new_fd;	
	int maxfd = srv_fd;
#if 0
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
#endif
	char kb_buf[32];
	char urg_buf[8];
	char recv_buf[1024];
	ret = -1;
	new_fd = 0;
	while(1)
	{
		FD_ZERO(&rd_set);
		FD_SET(srv_fd, &rd_set);	
		FD_SET(0, &rd_set);
		FD_SET(new_fd, &rd_set);

		/*init exp_set */
		FD_ZERO(&exp_set);
		FD_SET(new_fd, &exp_set);

		ret = select(maxfd+1, &rd_set, NULL, &exp_set, NULL);
		if(ret < 0)
			exit(1);
		if(ret > 0)
		{	
			if( FD_ISSET(srv_fd, &rd_set)){
				printf("new connect\n");
				new_fd = accept(srv_fd, NULL, NULL);
				maxfd = ((new_fd > maxfd)? new_fd : maxfd);
	
			}else if(FD_ISSET(0, &rd_set)){
				printf("data from keyboard\n");
				scanf("%s\n", kb_buf);
			}else if(FD_ISSET(new_fd, &rd_set)){
				printf("data from client \n");
				ret = read(new_fd, recv_buf, 1024);
				recv_buf[ret] = '\0';
				printf("read data from client: %s\n", recv_buf);
			}else if(FD_ISSET(new_fd, &exp_set)){
				ret = recv(new_fd, urg_buf, 8, MSG_OOB);
				urg_buf[ret] = '\0';
				printf("receive urg data: %s\n", urg_buf);
			}
		}
			
	}
	close(srv_fd);

	return 0;
}
