#include "net_all.h"

void catch_sig(int sig)
{
	printf("got sig chld\n");
        if(sig == SIGCHLD)
	{
                wait(NULL);
        }
}


int main(int argc, char *argv[])
{
	int srv_fd = -1;
	pid_t pid = -1;
	int new_fd = -1 ;
	char recv_buf[32];
	socklen_t len;
	struct sockaddr_in self_addr;
	struct sockaddr_in cli;

	signal(SIGCHLD, catch_sig);

	srv_fd = socket(PF_INET, SOCK_STREAM, 0);
	if(srv_fd < 0)
	{
		perror("socket");
		exit(1);
	} 
 	
	bzero(&self_addr, sizeof(self_addr));
	bzero(&cli, sizeof(cli));
	len = sizeof(cli);

 	self_addr.sin_family = PF_INET;
 	self_addr.sin_port = htons(22222);
	self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if( -1 == bind(srv_fd, (struct sockaddr *)&self_addr, sizeof(self_addr)))
 	{
 		printf("bind: %s\n", strerror(errno));
 	}
	
	listen(srv_fd, 10);
	
	int i = 0;
	while(1)
	{		
		new_fd = accept(srv_fd, (struct sockaddr *)&cli, &len);
		if(errno == EINTR)
			continue;
		printf("new connection: %dth connect\n", i++);
		pid = fork();
		if(pid == 0)
		{
			int num = -1;
			while(1)
			{
				num = read(new_fd, recv_buf, 32);
				if(num == 0)
					break;
				recv_buf[num] = '\0';
				printf("from client %s:%d: %s\n", inet_ntoa(cli.sin_addr), 
								ntohs(cli.sin_port),recv_buf);
			}
			close(new_fd);
			close(srv_fd);
			exit(1);
		}

	}
	close(new_fd);
	close(srv_fd);
	
	return 0;
}
