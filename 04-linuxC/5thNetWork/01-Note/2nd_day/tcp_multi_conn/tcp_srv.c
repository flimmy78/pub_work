
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>



#define SRV_PORT 9999


int main(int argc, char *argv[])
{

    // create a socket
    int srv_fd;
    int ret;
    char buf[128];

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
    int new_fd;
    printf("--------^_^ I'am waing.......\n");

    while(1)
    {
	//new_fd =  accept(srv_fd, NULL, NULL);
	struct sockaddr_in client_addr;
	socklen_t  len = sizeof(client_addr);
	new_fd =  accept(srv_fd,  (struct sockaddr *)&client_addr,  &len);
	if(new_fd < 0)
	{
	    perror("accept");
	    exit(1);
	}

	printf("we got a new client\n");
	printf("client ip : %s, port : %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	
	// fork child
	pid_t  pid = fork();
	
	if(pid == 0)// child
	{
	    //accept data
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
		    exit(1);
		}
		buf[ret] = '\0';
		printf("pid = %d, from client : %s\n", getpid(), buf);

	    }

	}
    }
   
    
    close(srv_fd);
    close(new_fd);

    return 0;

}

