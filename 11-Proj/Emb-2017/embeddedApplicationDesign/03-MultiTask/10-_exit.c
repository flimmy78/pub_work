/*******************************************************************
 *   > File Name: 10-_exit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 12 Dec 2017 08:06:21 AM PST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    puts("Using _exit...");
    printf("This is the content in buffer");/*加上回车符之后结果*/

    _exit(0);
}
