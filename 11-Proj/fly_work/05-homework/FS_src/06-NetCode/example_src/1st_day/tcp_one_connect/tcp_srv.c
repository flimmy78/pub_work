#include "net_all.h"

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int new_fd = -1;
	int ret = -1;
	int i = 1;
	int flags;
	char recv_buf[32];
	struct sockaddr_in self_addr;

	srv_fd = socket(PF_INET, SOCK_STREAM, 0);
	if(srv_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	
 	bzero(&self_addr, sizeof(self_addr));
 	self_addr.sin_family = PF_INET;
 	self_addr.sin_port = htons(22222);
	//self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	self_addr.sin_addr.s_addr = inet_addr("192.168.7.26");
	if( -1 == bind(srv_fd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
 	{
 		printf("bind: %s\n", strerror(errno));
 	}
	listen(srv_fd, 10);
	
	new_fd = accept(srv_fd, NULL, NULL);

	#ifdef NONBLOCK_TEST		
		flags = fcntl(new_fd, F_GETFL, 0);
		if(flag < 0)
		{
			perror("fcntl");
			exit(1);
		}
		fcntl(new_fd, F_SETFL, flags | O_NONBLOCK);
	#endif
	while(1)
	{
	#ifdef NONBLOCK_TEST		
		ret = read(new_fd, recv_buf, 32);
		if(ret < 0)
			perror("read");
	#else
		ret = read(new_fd, recv_buf, 32);
		if(ret == 0)
			break;
		recv_buf[ret] = '\0';
		printf("from peer %d: %s\n", i++,recv_buf);
	#endif
	}

	close(new_fd);
	close(srv_fd);
	
	return 0;
}
