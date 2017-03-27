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
#include <fcntl.h>
#include <signal.h>

#define MAXLEN 1024

void usage(void)
{
        printf("usage: commad <port> <save_file_name>\n");
        exit(-1);
}

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int file_fd = -1;
	int new_fd = -1;
	int num = -1;
	int on = 1;
	int ret = -1;
	struct sockaddr_in self;
	struct sockaddr_in peer;
	socklen_t peer_len = sizeof(peer);
	char recv_buf[MAXLEN];

	if(argc != 3)
		usage();

	file_fd = open(argv[2], O_CREAT | O_APPEND | O_RDWR, 0777);
	if(file_fd < 0)
	{
		perror("open");
		exit(1);
	}

	srv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(srv_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	ret = setsockopt(srv_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if(ret < 0)
	{
		perror("setsockopt");
		exit(1);
	}

	memset(&self, 0 , sizeof(self));
	memset(&peer, 0 , sizeof(peer));
	self.sin_family = AF_INET;
	self.sin_port = htons(atoi(argv[1]));
	self.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(srv_fd, (struct sockaddr *)&self, sizeof(self));
	if(ret < 0)
	{
			perror("bind");
			exit(1);
	}

	listen(srv_fd, 5);

	new_fd = accept(srv_fd, (struct sockaddr *)&peer, &peer_len);
	if(new_fd < 0)
	{
		perror("accept");
		exit(1);
	}
	
	while(1)
	{
		num = read(new_fd, recv_buf, MAXLEN);
		if(num == 0)
			break;
		write(file_fd, recv_buf, num);
	}

	close(file_fd);
	close(new_fd);
	close(srv_fd);
		
	return 0;
}
