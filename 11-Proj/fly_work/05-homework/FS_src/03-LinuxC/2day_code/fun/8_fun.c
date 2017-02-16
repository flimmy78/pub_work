#include <stdio.h>

 char * fun1(void)   //指针函数
{
    static char str[] = "hello world";

    return str;
}

int main(void)
{
    char *str;
    str = fun1();

    printf("%s\n",str);
    *str = 'H';	//.data中的数据可读可写
    printf("%s\n",str);
    return 0;
}
