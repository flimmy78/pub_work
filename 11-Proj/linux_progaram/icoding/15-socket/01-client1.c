/*******************************************************************
 *   > File Name: 01-client1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue May 23 14:04:58 2017
 ******************************************************************/
#if (0)
int socket(int domain, int type, int protocol);

#define UNIX_PATH_MAX   108
struct sockaddr_un{
    __kernel_sa_family_t sun_family;
    char sun_path[UNIX_PATH_MAX];
};
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int sockfd;
    int address_len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';
        
    /*create the file descriptor sockfd*/
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("sockfd");exit(EXIT_FAILURE);
    }
    

    address.sun_family = AF_UNIX;   /*Local communication*/
    strcpy(address.sun_path, "server_socket");
    address_len = sizeof(address);
    
    /*connect*/
    result = connect(sockfd, (struct sockaddr *)&address, address_len);

    if(result == -1){
        perror("oops:client1");exit(1);
    }
    
    /*write and read*/
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);

    return 0;
}

