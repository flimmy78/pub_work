#include <stdio.h>

int main(void)
{
	int i,j;

	i = 0;

	for(j = 0; j < 3;j++){
		while(i < 10){
			i++;
			if(i % 2 == 0)
				break;    //执行太该语句时，跳出while循环，但是不能跳出for循环
			printf("i = %d\n",i);
		}
		printf("while结束!\n");
	}
	printf("for结束!\n");
	return 0;
}
