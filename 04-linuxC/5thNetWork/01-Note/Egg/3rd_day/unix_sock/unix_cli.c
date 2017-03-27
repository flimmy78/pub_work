#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>

#define PATH_UNIX "/tmp/unix_socket"

int main(int argc , char *argv[])
{
	int cli_fd = -1;
	int ret = -1, send_num = -1;
	char send_buf[1024]= "hello";	
	
	struct sockaddr_un srv_addr;
	

	cli_fd = socket(PF_UNIX, SOCK_STREAM, 0);
	if(cli_fd < 0)
	{
		perror("socket");
		exit(1);
	}

	/* Clear structure */
	memset(&srv_addr, 0, sizeof(struct sockaddr_un));
	srv_addr.sun_family = PF_UNIX;
	strcpy(srv_addr.sun_path,  PATH_UNIX);
	
	ret = connect(cli_fd, (struct sockaddr *)&srv_addr, sizeof(struct sockaddr_un));
	if( ret < 0)
	{
		perror("connect");
		exit(1);
	}
	
	while( 1 ){
		fgets(send_buf, 1024, stdin);	
		send_num = write(cli_fd, send_buf, strlen(send_buf));
		
	}
	
	close(cli_fd);

	return 0;
}
