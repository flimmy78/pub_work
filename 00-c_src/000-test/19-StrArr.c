/*******************************************************************
 *   > File Name: 19-StrArr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 13 Feb 2017 10:56:11 AM CST
 ******************************************************************/

#include <stdio.h>

#define SGK "/dev/ttySGK"
#define USB "/dev/ttyUSB"

int main(int argc, char* argv[])
{
    char *dev[] = {SGK"0", SGK"1", SGK"2"};

    printf("sizeof dev = %d\n",sizeof dev);
    printf("sizeof dev[1] = %d\n",sizeof dev[0]);
    printf("sizeof dev[2] = %d\n",sizeof dev[1]);
    printf("sizeof dev[3] = %d\n",sizeof dev[2]);

    int i;
    for(i = 0; i < 3; i++)
    {
        printf("%s\n",dev[i]);
    }

    return 0;
}
