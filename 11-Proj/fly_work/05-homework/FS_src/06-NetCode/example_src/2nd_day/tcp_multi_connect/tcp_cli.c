#include "net_all.h"

int main(int argc, char *argv[])
{
	int cli_fd = -1;
	int count = 5;
	char *s = "hello";
	
	struct sockaddr_in peer_addr;

	cli_fd = socket(PF_INET, SOCK_STREAM, 0);
	
	bzero(&peer_addr, sizeof(peer_addr));
	peer_addr.sin_family = PF_INET;
	peer_addr.sin_port = htons(22222); 
	peer_addr.sin_addr.s_addr =  inet_addr("192.168.7.26");
	//inet_pton(PF_INET, argv[1], &peer_addr.sin_addr);
	if( -1 == connect(cli_fd, (struct sockaddr *)&peer_addr, sizeof(peer_addr)))
	{
		printf("connect : %s \n", strerror(errno));
	}
	
	while(count--){	
		write(cli_fd, s, strlen(s));
		sleep(1);
	}
	
	close(cli_fd);
	
	return 0;
}
