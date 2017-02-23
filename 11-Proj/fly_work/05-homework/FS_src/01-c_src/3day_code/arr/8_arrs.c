#include <stdio.h>

void fun(int n,int m,int b[][m])
{
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int a[][3] = {{1,2,3},{4,5,6}};   //完全初始化

	fun(2,3,a);    //数组传参：数组名和元素个数
}
