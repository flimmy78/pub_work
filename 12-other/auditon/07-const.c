/*******************************************************************
 *   > File Name: 07-const.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 23 Jul 2017 11:09:57 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    const int a = 100;  //const关键字，使a变为只读数据
    
    //a = 200;    // error: assignment of read-only variable ‘a’
    printf("a = %d\n", a);

    int *p;
    p = &a;
    *p = 200;   //可以通过指针修改变量值
    printf("a = %d\n", a);

    return 0;
}
