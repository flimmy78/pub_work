#include <stdio.h>

 char * fun1(void)   //指针函数
{
    return "hello world";
}

int main(void)
{
    char *str;
    str = fun1();

    printf("%s\n",str);
    //*str = 'H';	//常量区.rodata中的数据只能读，不能修改
    //printf("%s\n",str);
    return 0;
}
