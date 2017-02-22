#include "net_all.h"

int main(int argc, char *argv[])
{
	int cli_fd = -1;
	int count = 5;
	char *s1 = "hello";
	char *s2 = "world";
	struct sockaddr_in peer_addr;

	cli_fd = socket(PF_INET, SOCK_STREAM, 0);
	if(cli_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	
	bzero(&peer_addr, sizeof(peer_addr));
	peer_addr.sin_family = PF_INET;
	peer_addr.sin_port = htons(22222); 
	peer_addr.sin_addr.s_addr =  inet_addr("192.168.7.26");  
	if( -1 == connect(cli_fd, (struct sockaddr *)&peer_addr, sizeof(peer_addr)))
	{
		printf("connect : %s \n", strerror(errno));
	}
	
		#ifdef STREAM_TEST	
		while(1)
		{
			write(cli_fd, s1, strlen(s1));
			write(cli_fd, s2, strlen(s2));
		}
		#else
		while(count--)
		{
			write(cli_fd, s1, strlen(s1));	
			sleep(2);
		}
		#endif
	
	close(cli_fd);
	return 0;
}
