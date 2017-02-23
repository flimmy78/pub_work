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
	int cli_fd = -1;
	int count = 1;
	char *s = "hello";
	struct sockaddr_in peer_addr;
	struct sockaddr_in self_addr;
	
	cli_fd = socket(PF_INET, SOCK_STREAM, 0);

	bzero(&self_addr, sizeof(self_addr));
        self_addr.sin_family = PF_INET;
        self_addr.sin_port = htons(7899);
        //self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        self_addr.sin_addr.s_addr = inet_addr("192.168.7.26");
	if( -1 == bind(cli_fd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
        {
                printf("bind: %s\n", strerror(errno));
        }

	bzero(&peer_addr, sizeof(peer_addr));
	peer_addr.sin_family = PF_INET;
	peer_addr.sin_port = htons(7890); 
	peer_addr.sin_addr.s_addr =  inet_addr("192.168.7.26");  
	//inet_pton(PF_INET, "192.168.7.26", &peer_addr.sin_addr);
	if( -1 == connect(cli_fd, (struct sockaddr *)&peer_addr, sizeof(peer_addr)))
	{
		printf("connect : %s \n", strerror(errno));
	}
	while(1);
	
	
	close(cli_fd);
	
	return 0;
}
