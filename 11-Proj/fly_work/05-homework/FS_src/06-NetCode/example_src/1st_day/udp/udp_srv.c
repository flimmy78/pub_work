#include "net_all.h"

int main(int argc, char *argv[])
{
	int srv_fd = -1;
	int ret = -1;
	char recv_buf[32];
	struct sockaddr_in self_addr;
	srv_fd = socket(PF_INET, SOCK_DGRAM, 0);

	bzero(&self_addr, sizeof(self_addr));
        self_addr.sin_family = PF_INET;
        self_addr.sin_port = htons(22222);
        self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        //self_addr.sin_addr.s_addr = inet_addr("192.168.7.5");
        if( -1 == bind(srv_fd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
        {
                printf("bind: %s\n", strerror(errno));
        }
#ifdef SEND_LONG_DATA	
	struct file_info b;
	while(1)
	{
		ret = recvfrom(srv_fd, &b, sizeof(b), 0, NULL, NULL);
		printf("ret = %d\n", ret);
		if(-1 == ret)
			printf("sendto : %s\n", strerror(errno));
		printf("b.name = %s\n", b.name);
		//printf("b.size = %d\n", ntohl(b.size));
		printf("b.size = %d\n", b.size);
	}
#endif

#if defined(UDP_TEST) || defined(DGRAM_TEST)
	while(1)
	{
		ret = recvfrom(srv_fd, recv_buf, 32, 0, NULL, NULL);
		recv_buf[ret] = '\0';
		printf("from udp peer: %s\n", recv_buf);
	}
#endif
	close(srv_fd);

	return 0;
}
