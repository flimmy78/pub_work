#include <stdio.h>

int main(void)
{
	int i, j;

	puts("九九乘法表：");
	for(i = 1; i <= 9; i++)		/* 行循环 */	
	{
		for(j = 1; j <= i; j++)	/* 列循环 */
		{
			printf("%d * %d = %-2d  ",i,j,i*j);	/* 打印乘法表达式 */
		}
		puts("");
	}

	return 0;
}
