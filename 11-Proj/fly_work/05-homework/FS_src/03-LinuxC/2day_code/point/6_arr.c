#include <stdio.h>

void fun(int n,int m,int p[n][m])   //p为数组指针
//void fun(int n,int m,int(*p)[m])   //p为数组指针
{
    int i,j;
    for(i = 0; i < n ;i++){
	for(j = 0; j < m;j++)
	    printf("%d\t",p[i][j]);
	printf("\n");
    }
}

int main(void)
{
    int a[2][3] = {{1,2,3},{4,5,6}};

    fun(2,3,a);  //a作为数组名代表&a[0]，a[0]是一维数组
    return 0;
}
