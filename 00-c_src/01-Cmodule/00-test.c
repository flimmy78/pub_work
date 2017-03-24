/*******************************************************************
 *   > File Name: 00-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 06:53:31 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int diffVal;
    diffVal = atoi(argv[1]);

    int val1 = 100, val2 = 200;
    int ret;

    ret = (val1 > val2 && val1 - val2 > diffVal || val2 >val1 && val2 -val1 > diffVal);
    printf("ret = %d\n",ret);

    return 0;
}
