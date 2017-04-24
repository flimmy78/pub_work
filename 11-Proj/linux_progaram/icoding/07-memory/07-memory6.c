/*******************************************************************
 *   > File Name: 07-memory6.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 24 Apr 2017 06:26:05 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ONE_K   (1024)

int main(int argc, char* argv[])
{
    char *some_memory;
    int exit_code = EXIT_FAILURE;
    
    /*malloc*/
    some_memory = (char*)malloc(ONE_K);
    if(some_memory != NULL){
        /*free*/
        free(some_memory);
        printf("Memory allocated and freed again\n");
        exit_code = EXIT_SUCCESS;
    }

    exit(exit_code);
}
