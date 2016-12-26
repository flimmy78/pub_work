#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
	while(i < 10)
	{
		i ++ ;
		if(i % 2 == 0)
			continue;
		printf("i = %d\n",i);
	}
	
	return 0;
}
