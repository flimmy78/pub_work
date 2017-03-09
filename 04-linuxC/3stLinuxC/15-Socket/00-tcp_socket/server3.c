/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

#define SRV_IP 192.168.1.170
#define SRV_PORT 9999

#ifdef MY_DEBUG
int main()
{
    int server_sockfd, client_sockfd ;
    int server_len, client_len ;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

/*  Remove any old socket and create an unnamed socket for the server.  */

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);
    while(1) {
        char ch;

        printf("server waiting\n");

/*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);

/*  We can now read/write to client on client_sockfd.  */

        read(client_sockfd, &ch, 1);
        ch++;
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }
}
#else

int main(int argc,char *argv[])
{
	int server_sockfd, client_sockfd = -1;
	int server_len, client_len;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int ret;

	/* 移除所有旧的套接字，然后为服务端创建一个未被命名的套接字 */
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int on = 1;
	ret = setsockopt(server_sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	/* 命名这个套接字 */
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(SRV_PORT);
	server_len = sizeof(server_addr);

	/* 绑定套接字 */
	bind(server_sockfd, (struct sockaddr *)&server_addr,server_len);
	printf("SRV_IP : %s , SRV_PORT : %d \t",inet_ntoa(server_addr.sin_addr),ntohs(server_addr.sin_port));

	/* 创建一个连接队列，等待客户端的连接 */
	listen(server_sockfd,5);
	printf("Waiting for clients to connect !\n");
	
	/* start to select */
	int max_fd = server_sockfd;
	fd_set rd_set;
	FD_ZERO(&rd_set);

	char BufCache[128];
	int count = 1;

	while(1)
	{
		FD_SET(0,&rd_set);
		FD_SET(server_sockfd,&rd_set);
		FD_SET(client_sockfd,&rd_set);

		/* 确定一个或多个文件描述符的状态 */
		ret = select(max_fd+1,&rd_set,NULL,NULL,NULL);

		if(ret > 0)
		{	

			/* 确定键盘有输入 */
			if(FD_ISSET(0,&rd_set))
			{
				fgets(BufCache,128,stdin);
				if(client_sockfd > 0)
				{
					write(client_sockfd,BufCache,128);
				}
				else
				{
					printf("BufCache : %s \n",BufCache);
				}
			}
			
			/* 确定客户端有连接 */
			if(FD_ISSET(server_sockfd,&rd_set))
			{
				
				/* 接受一个连接 */		
				client_len = sizeof(client_addr);
				client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
				printf("SRV_IP : %s , SRV_PORT : %d \t",inet_ntoa(server_addr.sin_addr),ntohs(server_addr.sin_port));
				printf("a client connect ok ! CLI_IP : %s , CLI_PORT : %d \n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
				max_fd = client_sockfd;
			}
			
			/* 表示客户端有数据 */
			if(FD_ISSET(client_sockfd,&rd_set))
			{
				char ReadBuf[128];	

				bzero(ReadBuf,128);
				ret = read(client_sockfd,ReadBuf,128);

				if(ret < 0)
				{
					perror("read");
					exit(1);
				}
				if(ret == 0)
				{
					printf("client disconnect !\n");
					client_sockfd = -1;
					continue;
				}

				ReadBuf[ret] = '\0';
				printf("from client %d :%s \n",count,ReadBuf);
				count ++;
			}
		}
	}

#if 0
	while(1)
	{
		/* 接受一个连接 */		
		client_len = sizeof(client_addr);
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);
		printf("SRV_IP : %s , SRV_PORT : %d \t",inet_ntoa(server_addr.sin_addr),ntohs(server_addr.sin_port));
		printf("a client connect ok ! CLI_IP : %s , CLI_PORT : %d \n",inet_ntoa(client_addr.sin_addr),ntohs(server_addr.sin_port));

		char BufCache[1024];
		int count = 0;
		while(1)
		{
			
			bzero(BufCache,1024);
			printf("Please input :");
			scanf("%s",BufCache);

			ret = write(client_sockfd,BufCache,sizeof(BufCache));
			if(ret == -1)
			{
				perror("write");
			}

			bzero(BufCache,1024);
			ret = read(client_sockfd,BufCache,sizeof(BufCache) - 1);
			if(ret == -1)
			{
				perror("read");
			}else if(ret == 0)
			{
				printf("client is quit !\n");
				close(client_sockfd);
				break;
			}
			BufCache[ret] = '\0';
			count ++;
			printf("From client %d : %s\n",count,BufCache);
		}

	}
#endif

	return 0;
}

#endif
