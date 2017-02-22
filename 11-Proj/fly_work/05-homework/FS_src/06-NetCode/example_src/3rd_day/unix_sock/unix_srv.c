#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>

#define PATH_UNIX "/tmp/unix_socket"

int main(int argc , char *argv[])
{
	int srv_fd = -1;
	int conn_fd = -1;
	int ret = -1;
	int num = -1;
	char recv_buf[1024];	
	struct sockaddr_un srv_addr;
	
	srv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(-1 == srv_fd)
	{
		perror("socket");
		exit(1);
	}
	
	unlink(PATH_UNIX);
	
	memset(&srv_addr, 0, sizeof(struct sockaddr_un));
	srv_addr.sun_family = AF_UNIX;
	strcpy(srv_addr.sun_path, PATH_UNIX);
	ret = bind(srv_fd, (struct sockaddr *)&srv_addr, sizeof(struct sockaddr_un));
	if(ret < 0)
	{				
		perror("bind");
		exit(-1);
	}

	listen(srv_fd, 10);

	conn_fd = accept(srv_fd, NULL, NULL);
	if( conn_fd < 0)
	{
		perror("accept");
		exit(-1);
	}
	
	while( 1 ){	
		num = read(conn_fd, recv_buf, 64);
		if( num == 0) 
			break;
		recv_buf[num] = '\0';
		printf("from peer : %s \n ", recv_buf);
	}
	
	close(conn_fd);
	close(srv_fd);

	return 0;
}
