#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t value;
	
	value = time(NULL);
	printf("%ld\n",value);

	return 0;
}
