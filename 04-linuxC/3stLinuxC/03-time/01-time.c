#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t tm;
	
	//time(&tm);
	printf("%d\n",time(&tm));
	printf("%d\n",tm);

	return 0;
}
