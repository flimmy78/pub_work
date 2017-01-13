/*******************************************************************
 *   > File Name: 17-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 09:49:18 AM CST
 ******************************************************************/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned int a = 0;

    int i;
    for(i = 0; i < 10; i++)
    {
        a++;
        printf("loop a %d\n",a);
        sleep(1);
        while(a == 5)
        {
            printf("zero++");
            a = 0;
        }
    }

    unsigned int b = 4294967293U;
    int j;
    for(j = 0; j < 10; j++)
    {
        b++;
        printf("loop b %d\n",b);
        sleep(1);
    }
    return 0;
}
