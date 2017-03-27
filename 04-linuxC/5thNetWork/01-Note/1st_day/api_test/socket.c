#if (0)
int socket(int domain, int type, int protocol);
int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
/*---------------------------------------------------------------*/
struct sockaddr {
                   sa_family_t sa_family;
                    char        sa_data[14];
                };
/*--------------------------------------------------------------*/
struct sockaddr_in{
    _kernel_sa_family_t sin_family;
    _be16 sin_port;
    struct in_addr sin_addr;
    
    unsigned char     __pad[__SOCK_SIZE__ - sizeof(short int) -
    sizeof(unsigned short int) - sizeof(struct in_addr)];
};

#endif


#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>

#define IP  "192.168.1.170"

int main(int argc, char *argv[])
{
    int fd1;
    int fd2;
    int ret;
    
        /*创建数据流套接字*/
    fd1 = socket(AF_INET, SOCK_STREAM, 0);
    if(fd1 < 0)
    {
        perror("socket:");
        exit(1);
    }

    printf("fd1 = %d\n", fd1);

#if 1
    fd2 = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd2 < 0)
    {
        perror("socket:");
        exit(1);
    }
    printf("fd2 = %d\n", fd2);
#endif
        /* 填充地址 */
    struct sockaddr_in  self_addr;
    self_addr.sin_family = AF_INET;
    self_addr.sin_port = htons(9999);
    self_addr.sin_addr.s_addr = inet_addr(IP);
        
        /* 绑定套接字 */
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
