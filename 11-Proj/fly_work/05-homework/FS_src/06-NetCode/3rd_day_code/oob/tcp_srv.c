#include "net.h"

#define SRV_PORT 9999

static int new_fd;

void catch_signal(int signo)
{

    char buf;
    int ret;

    printf("we got a signal\n");
    if(signo == SIGURG)
    {
	printf("SIGURG is coming\n");
	ret = recv(new_fd, &buf, 1, MSG_OOB);	
	if(ret < 0)
	{
	    perror("recv");
	}

	printf("buf = %c\n", buf);
	if(buf == 's')
	{
	    printf("-----------start to play\n");
	}
	if(buf == 'p')
	{
	    printf("-----------stop play\n");
	}

    }

}

int main(int argc, char *argv[])
{

    // create a socket
    int srv_fd;
    int ret;
    char buf[128];

    signal(SIGURG, catch_signal);

    srv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(srv_fd < 0)
    {
	perror("socket");
	exit(1);
    }


    // bind addr
    struct sockaddr_in  self;
    self.sin_family = AF_INET;
    self.sin_port = htons(SRV_PORT);
    //self.sin_addr.s_addr = inet_addr("192.168.7.5"); //本机器的ip
    self.sin_addr.s_addr = htonl(INADDR_ANY); //本机器的所有ip
    ret = bind(srv_fd, (const struct sockaddr *)&self, sizeof(self));
    if(ret < 0)
    {
	perror("bind");
	exit(1);
    }


    // listen
    listen(srv_fd, 6);

    // accept
    printf("--------^_^ I'am waing.......\n");

    //new_fd =  accept(srv_fd, NULL, NULL);
    struct sockaddr_in client_addr;
    socklen_t  len = sizeof(client_addr);
    new_fd =  accept(srv_fd,  (struct sockaddr *)&client_addr,  &len);
    if(new_fd < 0)
    {
	perror("accept");
	exit(1);
    }

    // set sigurg owner
    fcntl(new_fd, F_SETOWN, getpid());
    
    printf("we got a new client\n");
    printf("client ip : %s, port : %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    while(1)
    {

	ret = read(new_fd, buf, 128);	
	if(ret < 0)
	{
	    perror("read");
	    exit(1);
	}
	if(ret == 0)
	{
	    printf("client disconnect\n");
	    break;
	}
	buf[ret] = '\0';
	printf("from client : %s\n", buf);

    }

    
    close(srv_fd);
    close(new_fd);

    return 0;

}

