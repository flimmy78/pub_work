/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

#ifdef DEBUG
int main()
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';

/*  Create a socket for the client.  */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.1.135");
    address.sin_port = htons(59571);
    len = sizeof(address);

/*  Now connect our socket to the server's socket.  */

    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client3");
        exit(1);
    }

/*  We can now read/write via sockfd.  */

    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);
    exit(0);
}
#else
int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("Usage: ./client3 SRV_IP SRV_PORT\n");
		exit(1);
	}
	else
	{
		printf("SRV_IP : %s \t SRV_PORT : %s\n",argv[1],argv[2]);
	}

	int cli_socket ;
	int ret ;
	int SRV_PORT;

	SRV_PORT = atoi(argv[2]);

	/* creat a socket for the client */

	cli_socket = socket(AF_INET,SOCK_STREAM,0);
	
	/*  Name the cli_socket , as agreed with the server . */

	struct sockaddr_in cli_addr;
	int cli_addr_len;
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_port = htons(SRV_PORT);
	cli_addr.sin_addr.s_addr = inet_addr(argv[1]);
	cli_addr_len = sizeof(cli_addr);
	
	/* connect the cli_socket to the server .  */

	ret = connect(cli_socket, (struct sockaddr *)&cli_addr,cli_addr_len);
	if(ret < 0)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("connect ok !\n");
	}

	/* read/write via cli_socket */
	char ReadBuf[1024];
	char sendMsg = '0';
	int count = 0;
	while(1)
	{
		bzero(ReadBuf,1024);	

		count++;
		ret = read(cli_socket,ReadBuf,sizeof(ReadBuf) - 1);
		if(ret == -1)
		{
			printf("read");
		}
		else if(ret == 0)
		{
			printf("server is quit !\n");
			exit(EXIT_FAILURE);
		}
		printf("Form server %d : %s\n",count,ReadBuf);

		ret = write(cli_socket,&sendMsg,1);
		if(ret == -1)
		{
			printf("write");
		}
		sendMsg++;
	}

	close(cli_socket);
}
#endif
