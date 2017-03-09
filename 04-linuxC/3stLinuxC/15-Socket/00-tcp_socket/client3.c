/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int main(int argc,char *argv[])
{
	if(argc < 3)
	{
		printf("Usage: ./client3 SRV_IP SRV_PORT\n");
		argv[1] = "192.168.1.170";
		argv[2] = "9999";
		printf("SRV_IP : %s \t SRV_PORT : %s    ",argv[1],argv[2]);
	}
	else
	{
		printf("SRV_IP : %s \t SRV_PORT : %s    ",argv[1],argv[2]);
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
	//start to select
	int max_fd = cli_socket;
	fd_set rd_set;
	FD_ZERO(&rd_set);

	ret = connect(cli_socket,(struct sockaddr *)&cli_addr,cli_addr_len);
	if(ret == -1)
	{
		perror("connect : ");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Connect ok ! Self_IP : %s , Self_Port : %d \n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));
	}

	char ReadBuf[1024] = {0};
	char sendMsg[128] = {0};
	char BufCache[128];
	int count = 1;

	while(1)
	{
		FD_SET(0,&rd_set);
		FD_SET(cli_socket,&rd_set);
		
		/* 确定一个或多个文件描述符的状态  */
		ret = select(max_fd+1,&rd_set,NULL,NULL,NULL);

		if(ret > 0)
		{
			/* 确定键盘有输入  */
			if(FD_ISSET(0,&rd_set))	
			{
				fgets(BufCache,128,stdin);
				ret = write(cli_socket,BufCache,128);
				//printf("BufCache : %s\n",BufCache);
				if(ret < 0)
				{
					perror("write : ");
					exit(EXIT_FAILURE);
				}
			}

			/* 确定服务器有数据 */
			if(FD_ISSET(cli_socket,&rd_set))
			{
				bzero(ReadBuf,1024);

				ret = read(cli_socket,ReadBuf,sizeof(ReadBuf) - 1);	
				if(ret == -1)
				{
					printf("read");
				}
				else if(ret == 0)
				{
					printf("server is quit !\n");
					break;
				}
				printf("Form server %d : %s\n",count,ReadBuf);

				sprintf(sendMsg,"%d  ACK : %d\n",count,strlen(ReadBuf));
				//printf("sendMsg : %s    sendMsgLen %d\n",sendMsg,strlen(sendMsg));
				ret = write(cli_socket,sendMsg,strlen(sendMsg));
				if(ret == -1)
				{
					printf("write");
				}

				count ++;
				
			}
		}

	}


#if 0
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
	char sendMsg[128];
	int count = 1;
	while(1)
	{
		bzero(ReadBuf,1024);	
		
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
		
		sprintf(sendMsg,"%d  ACK : %d",count,strlen(ReadBuf));
		//printf("sendMsg : %s    sendMsgLen %d\n",sendMsg,strlen(sendMsg));
		ret = write(cli_socket,sendMsg,strlen(sendMsg));
		if(ret == -1)
		{
			printf("write");
		}

		count++;
	}
#endif

	close(cli_socket);

	return 0;
}

