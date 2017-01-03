/*******************************************************************
 *   > File Name: 04-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 02 Jan 2017 04:14:49 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char a[] = {'a', 'b', 'c'};
    char b[] = {'d', 'e', 'f'};

    a[3] = '\0';
    b[3] = '\0';
    printf("strlen(a) = %d, strlen(b) = %d\n",strlen(a),strlen(b));
    printf("a = %s, b = %s\n",a,b);
    printf("sizeof(a) = %d,sizeof(b) = %d\n",sizeof(a),sizeof(b));
    
    return 0;
}
