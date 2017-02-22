#include "net.h"

#define SRV_PORT 9999
#define SRV_IP  "192.168.7.5"

int main(int argc, char *argv[])
{

    // create socket
    int ret;
    int count = 5;
    char *content = "hello server, come on baby";

    if(argc < 2)
    {
	printf("usage :  ./client  serverip\n");
	exit(1);
    }


    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
	perror("socket");
	exit(1);
    }

    // connect
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(SRV_PORT);
    //inet_aton(SRV_IP, &peer.sin_addr);    
    inet_aton(argv[1], &peer.sin_addr);    

    ret = connect(fd, (struct sockaddr *)&peer, sizeof(peer));
    if(ret < 0)
    {
	perror("connect");
	exit(1);
    }    

    while(count--)
    {
	ret = write(fd, content, strlen(content));
	if(ret < 0)
	{
	    perror("write");
	    exit(1);
	}
	sleep(1);    
    } 


    close(fd);

    return 0;

}

