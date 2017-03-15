/*******************************************************************
 *   > File Name: 12-getlogin.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 02:29:10 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("%s\n",getlogin());

    return 0;
}
