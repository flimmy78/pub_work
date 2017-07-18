/*******************************************************************
 *   > File Name: 03-arr_pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 13:42:23 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    int i;

    for(i = 0; i< 5; i++){
        printf("%d\t%d\n", a[i], *(a+i));
    }

    return 0;
}
