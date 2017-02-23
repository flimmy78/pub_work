#include <stdio.h>

int fun1(int a,int b)
{
    return a  + b;
}

void fun(int(*p)(int,int),int a,int b)
{
    printf("%d + %d = %d\n",a,b,p(a,b));
}

int main(void)
{
    int x,y;
    x = 20;
    y = 50;

    fun(fun1,x,y);   //函数fun1作为实参传递

    return 0;
}
