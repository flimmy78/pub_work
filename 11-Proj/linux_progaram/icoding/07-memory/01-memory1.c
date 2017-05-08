/*******************************************************************
 *   > File Name: 01-memory1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 04:13:38 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_MEGABYTE  (1024 * 1024)   //1MB

int main(int argc, char* argv[])
{
    char *some_memory;
    int megabyte = A_MEGABYTE;
    int exit_code = EXIT_SUCCESS;

    some_memory = (char*)malloc(megabyte);  //malloc the memory
    if(some_memory != NULL){
        sprintf(some_memory, "This is malloc test\n"); //use the memory
        printf("%s", some_memory);
        exit_code = EXIT_SUCCESS;
    }

    exit(exit_code);
}
