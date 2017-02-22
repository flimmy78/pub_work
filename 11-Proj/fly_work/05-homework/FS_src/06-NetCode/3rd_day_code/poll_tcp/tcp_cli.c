#include "net.h"

#define SRV_PORT 9999
#define SRV_IP  "192.168.7.5"

int main(int argc, char *argv[])
{

    // create socket
    int ret;
    int count = 5;
    char keybuf[128];
    char rbuf[128];
    int len = 0;
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

    // 监控多个文件
    struct pollfd pfd[2];

    pfd[0].fd = 0;
    pfd[0].events |= POLLIN;

    pfd[1].fd = fd;
    pfd[1].events |= POLLIN;

    while(1)
    {
	ret = poll(pfd, 2, -1);
	if(ret > 0)
	{
	    if(pfd[0].revents & POLLIN) //键盘有输入
	    {
		len = read(0, keybuf, 128);
		write(fd, keybuf, len);  //发送到服务端
		printf("keybuf = %s\n", keybuf);	    

	    }

	    if(pfd[1].revents & POLLIN)
	    {
		ret = read(fd, rbuf, 128);	   
		if(ret == 0)
		{
		    printf("servier disconnect");
		    exit(1);
		}

		rbuf[ret] = '\0';
		printf("rbuf from server : %s\n", rbuf);
	    }

	}
    }

    close(fd);

    return 0;

}

