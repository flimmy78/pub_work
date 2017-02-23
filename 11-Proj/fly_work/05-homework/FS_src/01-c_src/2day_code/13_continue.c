#include <stdio.h>

int main(void)
{
	int i;

	i = 0;

	while(i < 10){
		i++;
		if(i % 2 == 0)
			continue;   //执行该语句时，后面的的语句不执行直接跳转到第9行重新执行
		printf("i = %d\n",i);
	}
	return 0;
}
