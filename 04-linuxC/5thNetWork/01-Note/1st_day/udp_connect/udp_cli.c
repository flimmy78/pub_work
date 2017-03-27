
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/in.h>


#define SRV_PORT 9999
#define SRV_IP  "192.168.7.5"

int main(int argc, char *argv[])
{

    // create socket
    int ret;
    int count = 5;
    //char *content = "hello server, come on baby";
    char wbuf[128];

    if(argc < 2)
    {
        printf("usage :  ./client  serverip\n");
        exit(1);
    }


    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(SRV_PORT);
    //inet_aton(SRV_IP, &peer.sin_addr);    
    inet_aton(argv[1], &peer.sin_addr);    


    while(1)
    {
        printf("dear, pls input your words : \n");
        fgets(wbuf, 128, stdin);

        ret = sendto(fd, wbuf, 128, 0, (struct sockaddr *)&peer, sizeof(peer));
        if(ret < 0)
        {
            perror("sendto");
            exit(1);
        }
    } 


    close(fd);

    return 0;

}

