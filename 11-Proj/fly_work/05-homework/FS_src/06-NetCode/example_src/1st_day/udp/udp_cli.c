#include "net_all.h"

int main(int argc, char *argv[])
{
	int cli_fd = -1;
	int ret = -1;
	char *s = "hello udp";
	struct sockaddr_in peer_addr;
	cli_fd = socket(PF_INET, SOCK_DGRAM, 0);
	
	bzero(&peer_addr, sizeof(peer_addr));
	peer_addr.sin_family = PF_INET;
	peer_addr.sin_port = htons(22222);
	inet_pton(PF_INET, "192.168.7.26", &peer_addr.sin_addr);

#ifdef SEND_LONG_DATA	
	struct file_info  file_1;
	file_1.size = htonl(1024);
	strcpy(file_1.name, "hello");

	while(1){
		
		ret = sendto(cli_fd, &file_1, sizeof(file_1), 0, 
					(struct sockaddr *)&peer_addr, sizeof(peer_addr));
		printf("ret = %d\n", ret);
		if(-1 == ret)
			printf("sendto : %s\n", strerror(errno));
		sleep(2);
	}
#endif

#ifdef UDP_TEST
	printf("udp test\n");
	while(1)
	{	
		ret = sendto(cli_fd, s, strlen(s), 0, (struct sockaddr *)&peer_addr, sizeof(peer_addr));
		printf("ret = %d\n", ret);
		if(-1 == ret)
			printf("sendto : %s\n", strerror(errno));
		sleep(2);
	}
#endif

#ifdef DGRAM_TEST
	printf("dgram test\n");
	char *s2 = "world udp";
	while(1)
	{	
		ret = sendto(cli_fd, s, strlen(s), 0, (struct sockaddr *)&peer_addr, sizeof(peer_addr));
		ret = sendto(cli_fd, s2, strlen(s2), 0, (struct sockaddr *)&peer_addr, sizeof(peer_addr));
		printf("ret = %d\n", ret);
		if(-1 == ret)
			printf("sendto : %s\n", strerror(errno));
		sleep(2);
	}
#endif
	close(cli_fd);
	
	return 0;
}
