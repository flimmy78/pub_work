#include "net.h"
#define SRV_PORT 9999


int main(int argc, char *argv[])
{

    // create a socket
    int srv_fd;
    int ret;
    char buf[128];
    char keybuf[128];

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

    int new_fd = -1;
    printf("--------^_^ I'am waing.......\n");

    // start to select

    int maxfd = srv_fd;
    
    fd_set rd_set;

    FD_ZERO(&rd_set);
    
    while(1)
    { 
	FD_SET(0, &rd_set);
	FD_SET(srv_fd, &rd_set);
	FD_SET(new_fd, &rd_set);

	ret = select(maxfd+1, &rd_set, NULL, NULL, NULL);
	if(ret > 0) //表示有响铃--有数据
	{
	    if(FD_ISSET(0, &rd_set))//表示有键盘输入
	    {
		fgets(keybuf, 128, stdin); //此时不需要等了，一定可以拿到数据
		if(new_fd > 0)
		{
		    write(new_fd, keybuf, 128);	 
		}else{
		    printf("keybuf = %s\n", keybuf);
		}
	    }

	    if(FD_ISSET(srv_fd, &rd_set))//表示有客户端连接
	    {
		//new_fd =  accept(srv_fd, NULL, NULL);
		struct sockaddr_in client_addr;
		socklen_t  len = sizeof(client_addr);
		new_fd =  accept(srv_fd,  (struct sockaddr *)&client_addr,  &len);//accept就不会阻塞
		if(new_fd < 0)
		{
		    perror("accept");
		    exit(1);
		}

		printf("we got a new client\n");
		printf("client ip : %s, port : %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		//如果下次还有继续监控
		maxfd = new_fd;
	    }    	

	    if(FD_ISSET(new_fd, &rd_set)) //表示客户端有数据
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
		    new_fd = -1;
		    continue;
		}
		buf[ret] = '\0';
		printf("from client : %s\n", buf);

	    }

	}
    }




    
    close(srv_fd);
    close(new_fd);

    return 0;

}

