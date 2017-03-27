
#include "net.h"


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

    // step 1 : read file info
    struct file_info info;
    ret = read(new_fd, &info , sizeof(info));
    if(ret < 0)
    {
	perror("read info error\n");
	exit(1);
    }else{
	printf("read info ok\n");
    }

    printf("name = %s\n", info.name);
    printf("size = %d\n", ntohl(info.size));


    // 2 create a new file
    //组合一个路径
    char path[128];
    snprintf(path, 128, "%s/%s", "./target", info.name);
    printf("path = %s\n", path);

    int dst_fd = open(path, O_RDWR|O_CREAT|O_TRUNC, 0666);
    if(dst_fd < 0)
    {
	perror("open new file");
	exit(1);
    }


    printf("start to recv file....");
    size_t file_len = ntohl(info.size); //表示文件的总长度
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
	
	// write file
	if(file_len !=0 )
	{
	    ret = write(dst_fd, buf, ret);
	    file_len -= ret;
	}

	if(file_len == 0)
	    break;
    }
    printf("recv file done...\n");
    
    close(srv_fd);
    close(new_fd);
    close(dst_fd);

    return 0;

}

