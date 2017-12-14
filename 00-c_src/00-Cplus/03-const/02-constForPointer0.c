/*******************************************************************
 *   > File Name: 02-constForPointer0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 06:41:58 AM PST
 ******************************************************************/

#include <stdio.h>

#define KEY_TEST    0

int main(int argc, char* argv[])
{
    int a = 100;
    //int const *p = &a;//*p只读，等价于下面的语句
    const int *p = &a;

#if (KEY_TEST)
    *p = 200;//Err
#endif
    a = 200;
    printf("a = %d\n", a);

    return 0;
}
