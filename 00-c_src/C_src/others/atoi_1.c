#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
	if(argc < 3)
	{
		printf("Usage :./atoi_1 SRV_IP SRV_PORT\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int SRV_PORT = atoi(argv[2]);
		printf("SRV_IP : %s  SRV_PORT : %d \n",argv[1],SRV_PORT);
	}


	exit(EXIT_SUCCESS);
}
