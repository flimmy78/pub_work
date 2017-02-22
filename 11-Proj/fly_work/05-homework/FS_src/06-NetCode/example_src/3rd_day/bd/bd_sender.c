#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char input_buf[32];
	int num = -1;
	int ret = -1;
	
	int snd_fd = -1;
	int on = 1;
	snd_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(snd_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	/* active broadcast funcion*/	
	ret = setsockopt(snd_fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
	if(ret < 0)
	{
		perror("setsockopt");
		exit(1);
	}
		
	struct sockaddr_in bd_addr;
	memset(&bd_addr, 0 , sizeof(bd_addr));
	bd_addr.sin_family = AF_INET;
	bd_addr.sin_port = htons(7777);
	//bd_addr.sin_addr.s_addr = inet_addr("192.168.7.255");
	bd_addr.sin_addr.s_addr = inet_addr("255.255.255.255");
	
	while(1)
	{
		fgets(input_buf, 32, stdin);
		input_buf[strlen(input_buf)-1] = '\0';
		num = sendto(snd_fd, input_buf, strlen(input_buf), 0, (struct sockaddr *)&bd_addr, sizeof(bd_addr));
		printf("sendto %d bytes \n", num);
	}

	close(snd_fd);
	
}
