/*******************************************************************
 *   > File Name: 39-valPoint.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 03:54:31 PM CST
 ******************************************************************/

#include <stdio.h>

void fun(int *p1, int *p2){
    int t;
    printf("%d, %d\n", *p1, *p2);

    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

int main(int argc, char* argv[])
{
    int x = 20, y = 50;
    int *px = &x, *py = &y;

    printf("px = %p, py = %p\n", px, py);
    printf("x = %d, y = %d\n", x, y);
    fun(px, py);
    printf("px = %p, py = %p\n", px, py);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
