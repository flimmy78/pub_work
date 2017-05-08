/*******************************************************************
 *   > File Name: 02-memory2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 08 May 2017 04:26:18 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define A_MEGABYTE      (1024*1024)
#define PHY_MEM_MEGS    1024


int main(int argc, char* argv[])
{
    char *some_memory;
    size_t size_to_allocate = A_MEGABYTE;
    int megs_obtained = 0;

    while(megs_obtained < (PHY_MEM_MEGS * 2)){
        some_memory = (char*)malloc(size_to_allocate);  //申请内存
        if(some_memory != NULL){
            megs_obtained ++;
            sprintf(some_memory, "Hello World");
            //printf("%s - now allocated %d Megabytes\n", some_memory, megs_obtained);
            printf("%s %d - now allocated %d Megabytes\n", some_memory, megs_obtained, size_to_allocate);
        }else{
            exit(EXIT_FAILURE);
        }
    }
    sleep(5);
    
    exit(EXIT_SUCCESS);
}
