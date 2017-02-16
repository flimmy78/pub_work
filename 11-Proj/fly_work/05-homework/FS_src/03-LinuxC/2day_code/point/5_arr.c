#include <stdio.h>

char *fun1(void)
{
    char arr[] = "hello world";   //arr为字符数组
    return arr;   //不能返回自动存储类型数据的地址
}

char *fun2(void)
{
    char *arr = "hello world";   //arr为字符指针
    return arr;
}
int main(void)
{
    char *str;

    str = fun2();
    printf("%s\n",str);
    //arr[0] = 'H';
   // *str = 'H';   //不能修改.rodata中的数据
    //printf("%s\n",str);
    return 0;
}
