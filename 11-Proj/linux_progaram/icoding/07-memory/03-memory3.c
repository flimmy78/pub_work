/*******************************************************************
 *   > File Name: 03-memory3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 24 Apr 2017 04:57:11 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ONE_K (1024)

int main(int argc, char* argv[])
{
    char *some_memory;
    int size_to_allocate = ONE_K;
    int megs_obtained = 0;
    int ks_obtained = 0;

    while(1){
        for(ks_obtained = 0; ks_obtained < 1024; ks_obtained ++){
            some_memory = (char*)malloc(size_to_allocate);
            if(some_memory == NULL){
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            sprintf(some_memory, "Hello World");
        }
        megs_obtained ++;
        printf("%p--->Now allocated %d Megabyte\n",some_memory, megs_obtained);
    }

    exit(EXIT_SUCCESS);
}
