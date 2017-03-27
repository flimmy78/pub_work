
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>


#define SRV_PORT 9999


int main(int argc, char *argv[])
{

    // create a socket
    int srv_fd;
    int ret;
    char buf[128];

    srv_fd = socket(AF_INET, SOCK_DGRAM, 0);
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

    struct sockaddr_in info;
    socklen_t len = sizeof(info);

    while(1)
    {

        //直接读取数据
        ret = recvfrom(srv_fd, buf, 128, 0, (struct sockaddr *)&info, &len);
        if(ret < 0)
        {
            perror("read");
            exit(1);
        }

        buf[ret] = '\0';
        printf("from client %s (port %d) : %s\n", inet_ntoa(info.sin_addr), ntohs(info.sin_port), buf);

    }


    close(srv_fd);

    return 0;

}

