#include <stdio.h>

int main(void)
{
#if 1
    char *arr = "hello world";   //arr为字符指针

    printf("%s\n",arr);
    //arr[0] = 'H';
    *arr = 'H';
    printf("%s\n",arr);
#else
    char arr[] = "hello world";   //arr为字符数组

    printf("%s\n",arr);
    //arr[0] = 'H';
    *arr = 'H';
    printf("%s\n",arr);
#endif
    return 0;
}
