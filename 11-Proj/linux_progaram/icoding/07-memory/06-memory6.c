/*******************************************************************
 *   > File Name: 06-memory6.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 09 May 2017 09:39:00 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ONE_K   (1024)

int main(int argc, char* argv[])
{
    char *some_memory;
    int exit_code = EXIT_FAILURE;

    some_memory = (char*)malloc(ONE_K);
    if(some_memory != NULL){
        free(some_memory);
        printf("Memory allocated and freed again\n");
        exit_code = EXIT_SUCCESS;
    }

    exit(exit_code);
}
