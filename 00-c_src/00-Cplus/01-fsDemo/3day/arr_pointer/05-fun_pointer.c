/*******************************************************************
 *   > File Name: 05-fun.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 13:53:30 2017
 ******************************************************************/

#include <stdio.h>

/*说明：
 *函数指针：首先是一个指针变量，指向函数的入口地址
 *函数指针的作用：调用函数和做函数的参数
 * */

#if 0
void fun(int x, int y){
    printf("%d\t%d\n", x, y);
}

int main(int argc, char* argv[])
{
    int a = 5, b = 3;

    void(*p)(int, int); //p为函数指针
    p = fun;
    p(a, b);

    return 0;
}
#endif

#include <stdio.h>

void fun(int x, int y){
    printf("%d\t%d\n", x, y);
}

int main(void)
{
    int a = 5, b =3;

    void (*p)(int ,int);    //p为函数指针
    p = fun;
    p(a, b);

    return 0;
}
