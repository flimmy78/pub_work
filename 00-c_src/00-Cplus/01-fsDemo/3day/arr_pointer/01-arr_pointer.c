/*******************************************************************
 *   > File Name: 01-arr_pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 13:19:25 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[5] = {1, 2, 3, 4, 5};

    printf("&a[0] = %p\n", &a[0]);
    printf("&a[0] +  1 = %p\n", &a[0] + 1);
    printf("a = %p\n", a);
    printf("a + 1 =%p\n", a + 1);

    return 0;
}
