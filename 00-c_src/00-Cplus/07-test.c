/*******************************************************************
 *   > File Name: 07-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 05:17:22 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *)(&a + 1);

    printf("%d , %d\n",*(a+1),*(ptr - 1));

    return 0;
}
