#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t timep;
	time(&timep);

	printf("%s\n",ctime(&timep));
	return 0;
}
