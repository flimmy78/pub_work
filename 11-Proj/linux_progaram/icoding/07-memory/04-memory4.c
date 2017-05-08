/*******************************************************************
 *   > File Name: 04-memory4.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 05:38:55 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ONE_K (1024)

int main(int argc, char* argv[])
{
    char *some_memory;
    char *scan_ptr;
    int i = 0;

    some_memory = (char*)malloc(ONE_K); /*申请内存*/
    if(some_memory == NULL)
        exit(EXIT_FAILURE);

    scan_ptr = some_memory;
    while(1){
        i ++;
        *scan_ptr = '\0';/*赋值*/
        printf("%d-running...\n", i);
        scan_ptr ++;
    }

    return 0;
}
