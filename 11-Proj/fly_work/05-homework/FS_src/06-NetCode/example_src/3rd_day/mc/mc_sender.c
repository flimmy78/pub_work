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
	
	int snd_fd = -1;
	snd_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(snd_fd < 0)
	{
		perror("socket");
		exit(1);
	}
		
	struct sockaddr_in mc_addr;
	memset(&mc_addr, 0 , sizeof(mc_addr));
	mc_addr.sin_family = AF_INET;
	mc_addr.sin_port = htons(7890);
	mc_addr.sin_addr.s_addr = inet_addr("224.100.100.100");

	while(1)
	{
		fgets(input_buf, 32, stdin);
		input_buf[strlen(input_buf)-1] = '\0';
		num = sendto(snd_fd, input_buf, strlen(input_buf), 0, 
				(struct sockaddr *)&mc_addr, sizeof(mc_addr));
		if(num < 0)
		{
			perror("sendto");
			exit(1);
		}
		printf("sendto %d bytes: %s \n", num, input_buf);

	 }

	close(snd_fd);
	
	return 0;
}
