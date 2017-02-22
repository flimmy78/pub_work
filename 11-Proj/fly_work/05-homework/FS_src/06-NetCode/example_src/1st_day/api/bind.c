#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
        int sock_fd1 = -1;
        int sock_fd2 = -1;
        int ret = -1;
        sock_fd1 = socket(AF_INET, SOCK_STREAM, 0);
        //sock_fd2 = socket(AF_INET, SOCK_STREAM, 0);
        sock_fd2 = socket(AF_INET, SOCK_DGRAM, 0);
        printf("fd1 = %d, fd2 = %d\n", sock_fd1, sock_fd2);

        if((sock_fd1 < 0) || (sock_fd2 < 0))
                perror("socket");

        struct sockaddr_in self;
        bzero(&self, sizeof(self));
        self.sin_family = AF_INET;
        self.sin_port = htons(7890);
        self.sin_addr.s_addr = inet_addr("192.168.7.26");
        ret = bind(sock_fd1, (struct sockaddr *)&self, sizeof(self));
        if(ret < 0)
                perror("bind");
        ret = bind(sock_fd2, (struct sockaddr *)&self, sizeof(self));
        if(ret < 0)
                perror("bind");

        return 0;

}
