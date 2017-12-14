/*******************************************************************
 *   > File Name: 01-constForVar.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 06:11:00 AM PST
 ******************************************************************/

#include <stdio.h>

/*@Note:维修基本类型变量
 * */

#define KEY_TEST    0

int main(int argc, char* argv[])
{
    const int a = 100; //const关键字，使a变为只读数据

#if (KEY_TEST)
    a = 200;
#endif

    int *p;
    p = &a;
    *p = 200;
    printf("a = %d\n", a);

    return 0;
}
