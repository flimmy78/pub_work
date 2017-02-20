#include <stdio.h>

typedef void (*TF)(void);

void fun(void)
{
    printf("hello world\n");
}

int main(void)
{
    void *p;    //定义通用指针p，p中可以存储内存中任何类型的地址

    int a = 100;
    int *p1 = &a;
    p = &a;     //p中存放整型变量地址
    printf("%d\n",*(int*)p);
    printf("%d\n",*p1);

    p = &p1;	//p中存放整型指针变量地址
    printf("%d\n",**(int**)p);

    char ch = 'H';
    p = &ch;	//p中存放字符型变量地址
    printf("%c\n",*(char*)p);

    float f = 12.34;
    p = &f;	//p中存放浮点型变量地址
    printf("%f\n",*(float*)p);

    p = fun;
    ((TF)p)();
   return 0;
}
