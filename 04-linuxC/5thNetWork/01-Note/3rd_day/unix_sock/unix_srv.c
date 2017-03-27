
#include "net.h"

int main(int argc, char *argv[])
{
    int ret;
    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    char buf[128];


    unlink(UNIX_PATH);

    struct sockaddr_un  addr;
    addr.sun_family = AF_LOCAL;
    strncpy(addr.sun_path, UNIX_PATH, strlen(UNIX_PATH));
    
    ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if(ret < 0)
    {
	perror("bind");
	exit(1);
    }


    listen(fd, 5);

    
    int new_fd = accept(fd, NULL, NULL);
    

    while(1)
    {
	    ret = read(new_fd, buf, 128);
	    if(ret == 0)
	    {
		printf("client exit");
		break;
	    }
	    buf[ret] = '\0';
	    
	    printf("buf = %s\n", buf);
    }    


    close(fd);
    close(new_fd);

    return 0;

}
