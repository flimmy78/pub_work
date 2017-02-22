#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int cli_fd = -1;
	char input_buf[32];
	char recv_buf[32];
	struct sockaddr_in peer_addr;
	
	cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_fd < 0)
	{
		perror("socket");
		exit(1);
	}

	bzero(&peer_addr, sizeof(peer_addr));
	peer_addr.sin_family = AF_INET;
	peer_addr.sin_port = htons(7890);
	peer_addr.sin_addr.s_addr =  inet_addr("192.168.7.26");
	//inet_pton(PF_INET, "192.168.7.26", &peer_addr.sin_addr);
	if( -1 == connect(cli_fd, (struct sockaddr *)&peer_addr, sizeof(peer_addr)))
	{
		printf("connect : %s \n", strerror(errno));
	}
	fcntl(cli_fd, F_SETFL, O_NONBLOCK);
	while(1){	
		fgets(input_buf, 32, stdin);
		write(cli_fd, input_buf, 32);
		
	}
	
	close(cli_fd);
	
	return 0;
}
