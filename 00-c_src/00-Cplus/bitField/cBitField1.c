/*******************************************************************
 *   > File Name: cBitField1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 10:03:55 AM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

struct 
{
    unsigned int age : 3;
}Age;

int main(int argc, char* argv[])
{
    Age.age = 4;
    printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
    printf( "Age.age : %d\n", Age.age );

    Age.age = 7;
    printf( "Age.age : %d\n", Age.age );

    Age.age = 8;// warning: large integer implicitly truncated to unsigned type [-Woverflow]
    printf( "Age.age : %d\n", Age.age );

    return 0;
}
