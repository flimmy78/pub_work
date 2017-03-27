#include <sys/types.h>          
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLEN 1024

void usage(void)
{
	printf("command   <file_name>\n");
	exit(1);
	
}

int main(int argc, char *argv[])
{
	int cli_fd = -1;
	int file_fd = -1;
	int ret = -1;
	int num = -1;
	char buf[MAXLEN];
	struct sockaddr_in  srv_addr;  
	
	if(argc != 2 )
		usage();
	
	file_fd = open(argv[1], O_RDONLY);
	if(file_fd < 0)
	{
		perror("open");
		exit(1);
	}

	cli_fd = socket( AF_INET, SOCK_STREAM,  0);
	if(cli_fd < 0)
	{
		perror("socket");
		exit(1);
	}

	memset(&srv_addr,  0 , sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port =  htons(7890);
	srv_addr.sin_addr.s_addr = inet_addr("192.168.7.100");
				  
	ret = connect(cli_fd,  (struct sockaddr *)&srv_addr,   sizeof(srv_addr));
	if(ret < 0)
	{
		perror("connect");
		exit(1);
	}
	printf("start tranfer .....\n");
	while(1)
	{	
		num = read(file_fd, buf, MAXLEN);
		if(num == 0)
			break;
		write(cli_fd, buf,  num);
	}
	printf("tranfer done.....\n");

	close(file_fd);
	close(cli_fd);

	return 0;
	
}
