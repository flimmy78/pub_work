#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t timep;
	int time_value;
	
	time_value = time(&timep);
	
	printf("time : %d\n",time_value);
	printf("time : %s",ctime(&timep));

	exit(EXIT_SUCCESS);
}
