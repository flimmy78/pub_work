#include <stdio.h>
#include <stdlib.h>

int fun_0(void)
{
	int i = 3;
	printf(" i = %d , (++i)*(++i) = %d , i = %d\n",
			i,(++i)*(++i),i);
	return 0;
}

int main(void)
{
	fun_0();

	exit(EXIT_SUCCESS);
}


