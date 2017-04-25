/*******************************************************************
 *   > File Name: 04-memory4.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 24 Apr 2017 05:30:22 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ONE_K (1024)

int main(int argc, char* argv[])
{
    char *some_memory;
    char *scan_ptr;
    
    /*分配内存*/
    some_memory = (char*)malloc(ONE_K);
    if(some_memory == NULL){
        perror("malloc");exit(EXIT_FAILURE);
    }

    /*尝试在内存之后写东西*/
    scan_ptr = some_memory;
    while(1){
        *scan_ptr = '\0';
        scan_ptr ++;//Segmentation fault (core dumped)
    }

    exit(EXIT_SUCCESS);
}
