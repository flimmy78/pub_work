/*******************************************************************
 *   > File Name: 00-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 15 May 2017 05:49:06 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int open_mode = 0;
    int RDONLY = 1;
    int WRONLY = 2;
    int NONBLOCK = 3;

    printf("open_mode : %d\tRDONLY : %d\tWRONLY : %d\t NONBLOCK : %d\n", \
            open_mode, RDONLY, WRONLY, NONBLOCK);

    if(argc != 2){
        printf("Usage : %s <key>\n", argv[0]);exit(EXIT_FAILURE);
    }

    int key = atoi(argv[1]);
    if(key == 1){
        open_mode |= RDONLY;
        printf("open_mode :%d\n", open_mode);
    }else if(key == 2){
        open_mode |= WRONLY;
        printf("open_mode :%d\n", open_mode);
    }else if(key == 3){
        open_mode |= NONBLOCK;
        printf("open_mode :%d\n", open_mode);
    }else if(key == -1){
        open_mode &= RDONLY;
        printf("Open_mode :%d\n", open_mode);
    }else if(key == -2){
        open_mode &= WRONLY;
        printf("Open_mode :%d\n", open_mode);
    }else if(key == -3){
        open_mode &= NONBLOCK;
        printf("Open_mode :%d\n", open_mode);
    }

    return 0;
}
