/*******************************************************************
 *   > File Name: gets.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 02:19:00 PM CST
 ******************************************************************/
#include <stdio.h>

int main( )
{
    char str[5];

    printf( "Enter a value :");
    gets( str );

    printf( "\nYou entered: ");
    puts( str );
    return 0;
}
