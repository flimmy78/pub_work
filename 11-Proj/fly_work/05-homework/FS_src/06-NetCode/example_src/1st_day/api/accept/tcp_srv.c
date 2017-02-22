#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int new_fd = -1;
	int ret = -1;
	char input[64];
	char recv_buf[32];
	struct sockaddr_in self_addr;

	srv_fd = socket(PF_INET, SOCK_STREAM, 0);
	
 	bzero(&self_addr, sizeof(self_addr));
 	self_addr.sin_family = PF_INET;
 	self_addr.sin_port = htons(7890);
	//self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	self_addr.sin_addr.s_addr = inet_addr("192.168.7.26");
	if( -1 == bind(srv_fd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
 	{
 		printf("bind: %s\n", strerror(errno));
 	}
	listen(srv_fd, 10);
	
	while(1);
	new_fd = accept(srv_fd, NULL, NULL);
	printf("new_fd = %d\n", new_fd);

	close(new_fd);
	close(srv_fd);
	
	return 0;
}
