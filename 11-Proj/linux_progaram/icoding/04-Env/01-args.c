/*******************************************************************
 *   > File Name: 01-args.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Mar 2017 09:03:28 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int arg;

    for(arg = 0; arg < argc ; arg ++){
        if(argv[arg][0] == '-')
            printf("option :%s\n",argv[arg] + 1);
        else
            printf("argument %d: %s\n", arg, argv[arg]);
    }

    return 0;
}
