#include <stdio.h>

void fun(int ,int m,int b[][m]); //函数的原型声明，m，b是函数原型作用域
int  main(void)
{
	int a[2][3] = {{1,2,3},{4,5,6}};

	fun(2,3,a);
	return 0;
}
void fun(int n,int m,int b[n][m])
{
	int i,j;

	for(i = 0;i < n; i++){
		for(j = 0; j < m; j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
}


