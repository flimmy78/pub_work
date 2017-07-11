/*******************************************************************
 *   > File Name: 3-arr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 03:33:03 PM CST
 ******************************************************************/

#include <stdio.h>

/*说明：指定元素初始化
 *
 * */

int main(int argc, char* argv[])
{
    int a[10] = {[3] = 100, 101, 102, [8] = 80, [4] = 400, 500};

    printf("a[3] = %d\n", a[3]);
    printf("a[4] = %d\n", a[4]);
    printf("a[5] = %d\n", a[5]);

    return 0;
}
