#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i,j;

	i = 0;
	for(j = 0; j<3 ; j++)
	{
		while(i < 10)
		{
			i ++ ;
			if(i % 2 == 0)
				break;		//直接跳出while循环，不跳出for循环 
			printf("i = %d\n",i);
			sleep(1);
		}
		printf("while循环结束！\n");
		sleep(1);
	}
	printf("for循环结束！\n");

	return 0;
}
