#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

void err_sys(char *err_str)
{
	perror(err_str);
	exit(1);
}

int main(int argc, char *argv[])
{
	int cli_fd = -1;
	int count = 5;
	int ret = -1;
	char *s = "hello";
	struct sockaddr_in peer;

	cli_fd = socket(PF_INET, SOCK_STREAM, 0);
	if(cli_fd < 0)
		err_sys("socket");
	
	bzero(&peer, sizeof(peer));
	peer.sin_family = PF_INET;
	peer.sin_port = htons(22222); 
	peer.sin_addr.s_addr =  inet_addr("192.168.7.5");  
	ret = connect(cli_fd, (struct sockaddr *)&peer, sizeof(peer));
	if(ret < 0 )
		err_sys("connect");
	
	while( count--)
	{	
		write(cli_fd, s, strlen(s));
		sleep(3);
	}

	close(cli_fd);
	
	return 0;
}
