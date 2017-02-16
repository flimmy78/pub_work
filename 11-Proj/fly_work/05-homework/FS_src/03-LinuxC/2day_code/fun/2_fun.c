#include <stdio.h>

void fun1(int* a,int* b)
{
    scanf("%d%d",a,b);
}
void fun2(int* a,int* b)
{
    *a *=  2;
    *b *=  3;
}

int main(void)
{
    int x,y;

    fun1(&x,&y);
    printf("x=%d,y=%d\n",x,y);
    fun2(&x,&y);   //基本类型变量的地址传递
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
