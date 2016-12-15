#include <stdio.h>
#include <stdlib.h>

#define Printf(string...)	\
	do{\
		printf("%s\t%s\t%d\t",__FILE__,__func__,__LINE__);\
		printf(string);\
	}while(0)

int main(int argc, char *argv[])
{
	Printf("Parameter transfer test !\n");

	printf("argc = %d\n",argc);
#if 1
	int i;
	for(i = 0; i < argc ; i++)
	{
		if(i == 0)
			printf("Run : %s\n ",argv[0]);
		else
			printf("Parameter %d is : %s\n",i,argv[i]);
	}
#endif

	exit(EXIT_SUCCESS);
}
