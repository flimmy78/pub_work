/*******************************************************************
 *   > File Name: 02-arr_pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 13:36:39 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[5] = {1, 2, 3, 4, 5};

    printf("a = %p\n", a);
    printf("a + 1 = %p\n", a + 1);
    printf("&a = %p\n", &a);
    printf("&a + 1 = %p\n", &a + 1);

    return 0;
}
