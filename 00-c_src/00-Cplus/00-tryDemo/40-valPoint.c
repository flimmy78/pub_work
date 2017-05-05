/*******************************************************************
 *   > File Name: 40-valPoint.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 04:08:14 PM CST
 ******************************************************************/

#include <stdio.h>

void fun2(int **p1, int **p2){
    int t;
    t = **p1;
    **p1 = **p2;
    **p2 = t;
}

int main(int argc, char* argv[])
{
    int x = 20, y = 50;
    int *px = &x, *py = &y;

    printf("px = %p, py = %p\n", px, py);
    printf("x = %d,y = %d\n", x, y);
    fun2(&px, &py);
    printf("px = %p, py = %p\n", px, py);
    printf("x = %d,y = %d\n", x, y);

    return 0;
}
