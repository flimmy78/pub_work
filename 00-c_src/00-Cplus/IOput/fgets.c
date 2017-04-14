/*******************************************************************
 *   > File Name: fgets.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 02:20:54 PM CST
 ******************************************************************/
#include <stdio.h>

int main( )
{
    char str[5];

    printf( "Enter a value :");
    fgets( str,5,stdin );      //fgets()函数;

    printf( "\nYou entered: ");
    puts( str );
    return 0;
}
