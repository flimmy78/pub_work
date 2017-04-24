/*******************************************************************
 *   > File Name: 01-memory1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 24 Apr 2017 03:46:13 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define A_MEGABYTE (1024*1024)

int main(int argc, char* argv[])
{
    char *some_memory;
    int megabyte = A_MEGABYTE;
    int exit_code = EXIT_FAILURE;

    some_memory = (char *)malloc(megabyte);
    if(some_memory != NULL){
        sprintf(some_memory, "Hello World\n");
        printf("%s", some_memory);
        exit_code = EXIT_SUCCESS;
    }

    exit(exit_code);
}
