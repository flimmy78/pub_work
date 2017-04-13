/*******************************************************************
 *   > File Name: 14-testBit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 03 Jan 2017 05:13:03 PM CST
 ******************************************************************/

#include <stdio.h>


int main(void)
{   
    int arr[8];
    char value;
    int main_run = 1;

    while(main_run)
    {
        printf("Pls input a char : ");
#if (0)
        scanf("%c",&value);
        printf("Entry char is : %c\n",value);
#else
        value = fgetc(stdin);
        printf("Get a char %c\n",value);
#endif
    }

    return 0;
}
