#include <stdio.h>

//void fun1(int n,int m,int b[][m])    //数组形式定义b
void fun1(int n,int m,  int(*b)[m])	//指针形式定义b
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
    int a[2][3] = {{1,2,3},{4,5,6}};

    fun1(2,3,a);    //地址传递
    return 0;
}
