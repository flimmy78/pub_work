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
	int cli_fd = -1;
	int ret = -1;
	int num = -1;
	char send_buf[LEN];
	char *str = "hello tcp";
	struct sockaddr_in peer;

	cli_fd = socket(AF_INET,  SOCK_STREAM, 0);
	if(cli_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	
	bzero(&peer, sizeof(peer));
	peer.sin_family = AF_INET;
	peer.sin_port = htons(7890);
	peer.sin_addr.s_addr = inet_addr("192.168.7.100");
	ret = connect(cli_fd, (struct sockaddr *)&peer, sizeof(peer));
	assert(ret == 0);
	#if 0
	if(ret < 0)
	{
		perror("conncet");
		exit(1);
	}
	#endif
	printf("connect success\n");
	while(1)
	{
		fgets(send_buf, LEN, stdin);
		num = write(cli_fd, send_buf, strlen(send_buf));
		if(num < 0)
		{
			perror("write");
			exit(1);
		}
	}	

	close(cli_fd);

	return 0;
}
