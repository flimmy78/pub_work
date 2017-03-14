/*******************************************************************
 *   > File Name: 05-showenv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Mar 2017 10:43:22 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char* argv[])
{
    char **env = environ;

    while(*env){
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
