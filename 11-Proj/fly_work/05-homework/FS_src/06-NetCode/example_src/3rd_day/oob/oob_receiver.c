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
#include <assert.h>

int new_fd = -1;

void catch_urg(int arg)
{
	char buf[10];
	int num = -1;
	printf("there is a signal named SIGURG come\n");
	num = recv(new_fd, buf, 1, MSG_OOB);
	buf[num] = '\0';
	if( !strcmp(buf, "L") ){
		printf("AAAAAAAA\n");
	}
	printf("%s_%d: %s\n", __FUNCTION__, __LINE__, buf);

}

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int num = -1;
	int on = 1;
	int ret = -1;
	struct sockaddr_in self_addr;
	struct sockaddr_in peer_addr;
	socklen_t peer_len = sizeof(peer_addr);
	char recv_buf[32];

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

	memset(&self_addr, 0 , sizeof(self_addr));
	memset(&peer_addr, 0 , sizeof(peer_addr));
	self_addr.sin_family = AF_INET;
	self_addr.sin_port = htons(7890);
	self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(srv_fd, (struct sockaddr *)&self_addr, sizeof(self_addr));
	assert(ret == 0);	

	listen(srv_fd, 5);

	new_fd = accept(srv_fd, (struct sockaddr *)&peer_addr, &peer_len);
	assert(new_fd > 0);

	signal(SIGURG, catch_urg);
	/* must be here*/
	fcntl(new_fd, F_SETOWN, getpid());
	
	while(1)
	{
		num = read(new_fd, recv_buf, 32);
		if(num == 0)
			break;
		recv_buf[num] = '\0';
		printf("read normal data: %s\n", recv_buf);
	}

	
	close(new_fd);
	close(srv_fd);
		
	return 0;
}
