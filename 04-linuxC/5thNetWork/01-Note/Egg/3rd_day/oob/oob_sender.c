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


int main(int argc, char *argv[])
{
	int snd_fd = -1;
	char *buf = "a";
	int ret = -1;
	snd_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(snd_fd < 0)
	{
		perror("socket");
		exit(1);
	}
	
	struct sockaddr_in peer_addr;
	memset(&peer_addr, 0 , sizeof(peer_addr));
	peer_addr.sin_family = AF_INET;
	peer_addr.sin_port = htons(7890);
	peer_addr.sin_addr.s_addr = inet_addr("192.168.7.2");
	ret = connect(snd_fd,(struct sockaddr *)&peer_addr, sizeof(peer_addr));
	if(ret < 0)
	{
		perror("connect");
		exit(1);
	}

	while(1)
	{
		write(snd_fd, buf, strlen(buf)); // normal data
		sleep(3);
		send(snd_fd, "L",  1, MSG_OOB); // out of band data
		sleep(3);
		write(snd_fd, "H", 1); // normal data
		sleep(3);
		send(snd_fd, "efg",  3, MSG_OOB); // out of band data
		sleep(3);
	}	
	
	close(snd_fd);
	
	return 0;
}
