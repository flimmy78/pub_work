#include <stdio.h>

void fun1(int a,int b)
{
    printf("%d,%d\n",a,b);
}

int main(void)
{
    int x,y;
    x = 20;
    y = 50;
    fun1(x,y);   //基本类型变量的值传递
    return 0;
}
