#include "net.h"


int main(int argc, char *argv[])
{
    int ret;
    char keybuf[128];

    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);
   
    // peer addr
    struct sockaddr_un peer;
    peer.sun_family = AF_LOCAL;
    strncpy(peer.sun_path, UNIX_PATH, strlen(UNIX_PATH));
 
    ret =  connect(fd, (struct sockaddr *)&peer, sizeof(peer));
    if(ret < 0)
    {
	perror("connect");
	exit(1);
    }

    while(1)
    {
	printf("pls input : \n");
	fgets(keybuf, 128, stdin);
	write(fd, keybuf, 128);
    }


    close(fd);

    return 0;
}
