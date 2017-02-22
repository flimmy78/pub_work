#include "net.h"

#define SRV_PORT 9999
#define SRV_IP  "192.168.7.5"

int main(int argc, char *argv[])
{

    // create socket
    int ret;
    int count = 5;
    char *content = "hello server, come on baby";
    char buf[32];
    struct file_info info;


    if(argc < 3)
    {
	printf("usage :  ./client  serverip filename\n");
	exit(1);
    }


    // open a file
   int src_fd =  open(argv[2], O_RDWR);
    if(src_fd < 0)
    {
	perror("open file");
	exit(1);
    }    


    //封装
    char *p = strrchr(argv[2], '/');
    printf("p = %s\n", p);

    //info.name = argv[2];
    //info.name = ++p;
    memcpy(info.name, ++p, strlen(p));
    struct stat stat;
    fstat(src_fd, &stat);
    info.size = htonl(stat.st_size);
    printf("name = %s, size = %d\n", info.name, info.size);  


    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0)
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

    ret = connect(sock_fd, (struct sockaddr *)&peer, sizeof(peer));
    if(ret < 0)
    {
	perror("connect");
	exit(1);
    }    

    // step 1  tranfer file info

    write(sock_fd, &info, sizeof(info));
    //sleep(1);

    // step 2 transfer file data
    while(1)
    {
	// read file
	ret = read(src_fd, buf, 32);
	if(ret < 0)
	{
	    perror("read file");
	    exit(1);
	}

	if(ret == 0)
	{
	    printf("file tranfer done....\n");
	    break;
	}
	// send file data to server
	ret = write(sock_fd, buf, ret);
	if(ret < 0)
	{
	    perror("write");
	    exit(1);
	}
    } 

    while(1);//测试是否完成

    close(src_fd);
    close(sock_fd);

    return 0;

}

