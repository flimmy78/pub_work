 #include <sys/select.h>

       /* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	struct timeval tv;
	int retval;

	fd_set rfds;
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);
	FD_SET(1,&rfds);
	FD_SET(2,&rfds);
	int maxfd = 2;

	tv.tv_sec = 5;
	tv.tv_usec = 0;

	printf("Test0\n");
	retval = select(maxfd + 1,&rfds,NULL,NULL,&tv);
	printf("Test1\n");
	switch(retval)
	{
		case 0:
			printf("Time out , no data within 5s .\n");
			break;
		case -1:
			perror("seletc()");
			break;
		default:
			if(FD_ISSET(0,&rfds))
			{
				printf("0 : We got a data .\n");
			}
			else if(FD_ISSET(1,&rfds))
			{
				printf("1 : We got a data .\n");
			}
			else /*FD_ISSET(2,&rfds) will be true*/
			{
				printf("2 : We got a data .\n");
			}
			break;
	}
	
		
	exit(EXIT_SUCCESS);
}
