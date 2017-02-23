#include <stdio.h>

//void fun1(int n,int b[])  //数组形式定义b
void fun1(int n,int *b)	    //指针形式定义b
{
    int i;
    for(i = 0; i < n ;i++)
	printf("%d\t",b[i]);
    printf("\n");
}

//void fun2(int n,int b[])
void fun2(int n,int *b)
{
    int i;
    for(i = 0; i < n ;i++)
	b[i] *= 2;
}
int main(void)
{
    int a[] = {1,2,3,4,5};

    fun1(5,a);   //地址传递
    fun2(5,a);
    fun1(5,a);
    return 0;
}
