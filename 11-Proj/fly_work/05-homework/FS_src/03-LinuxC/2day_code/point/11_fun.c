#include <stdio.h>

int fun1(int a,int b)
{
    return a + b;
}
int fun2(int a,int b)
{
    return a - b;
}
int fun3(int a,int b)
{
    return a * b;
}
int fun4(int a,int b)
{
    return a / b;
}

int main(void)
{
    int a = 5,b = 3;
#if 0
    int(*p)(int,int);	//p为函数指针
    p = fun1;
    printf("%d\n",p(a,b));
    p = fun2;
    printf("%d\n",p(a,b));
    p = fun3;
    printf("%d\n",p(a,b));
    p = fun4;
    printf("%d\n",p(a,b));
#else
    int (*arr[4])(int,int) = {fun1,fun2,fun3,fun4};   //arr为函数指针数组
    int i;

    for(i = 0 ; i < 4; i++)
	printf("%d\n",arr[i](a,b));
#endif
    return 0;
}
