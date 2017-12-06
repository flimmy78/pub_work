#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>

int main(int argc, char *argv[])
{
    int fd1;
    int fd2;
    int ret;

    fd1 = socket(AF_INET, SOCK_STREAM, 0);
    if(fd1 < 0)
    {
	perror("socket:");
	exit(1);
    }

     printf("fd1 = %d\n", fd1);

#if 0
    fd2 = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd2 < 0)
    {
	perror("socket:");
	exit(1);
    }
     printf("fd2 = %d\n", fd2);
#endif

    struct sockaddr_in  self_addr;
    self_addr.sin_family = AF_INET;
    self_addr.sin_port = htons(9999);
    self_addr.sin_addr.s_addr = inet_addr("0.0.0.0");//inet_addr("192.168.7.5");

    ret = bind(fd1, (const struct sockaddr * )&self_addr,   sizeof(self_addr));
    if(ret < 0)
    {
	perror("bind");
	exit(1);
    }
    printf("bind ok\n");



    close(fd1);
    close(fd2);

    return 0;
}
