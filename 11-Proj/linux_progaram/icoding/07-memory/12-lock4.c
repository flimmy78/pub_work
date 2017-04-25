/*******************************************************************
 *   > File Name: 12-lock4.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 25 Apr 2017 01:52:24 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

const char *test_file = "/tmp/test_lock";
#define SIZE_TO_TRY     4

void show_lock_info(struct flock *to_show);

int main(int argc, char* argv[])
{
    int file_desc;
    int res;
    struct flock region_to_test;
    int start_byte;
    
    /*open a file descriptor*/
    file_desc = open(test_file, O_RDWR | O_CREAT , 0666);
    if(!file_desc){
        fprintf(stderr, "Unable to open %s for read/write", test_file);exit(EXIT_FAILURE);
    }

    for(start_byte = 0; start_byte < 99; start_byte += SIZE_TO_TRY){
        /*set the file region , you hope*/
        region_to_test.l_type = F_WRLCK;        //独占锁
        region_to_test.l_whence = SEEK_SET;     //文件头
        region_to_test.l_start = start_byte;
        region_to_test.l_len = SIZE_TO_TRY;
        region_to_test.l_pid = -1;
        
        printf("Testing F_WRLCK on region from %d to %d\n", start_byte, start_byte + SIZE_TO_TRY);
        /*test the lock of file*/
        res = fcntl(file_desc, F_GETLK, &region_to_test);   //获取锁状态
        if(res == -1){
            fprintf(stderr, "F_GETLK failed\n");exit(EXIT_FAILURE);
        }
        //show_lock_info(&region_to_test);

        if(region_to_test.l_pid != -1){
            printf("Lock would fail . F_GETLK returned :\n");
            show_lock_info(&region_to_test);
        }else{
            printf("F_WRLCK - Lock would succeed\n");
        }
        
        /*use the share lock test again*/
        region_to_test.l_type = F_RDLCK;        //共享锁
        region_to_test.l_whence = SEEK_SET;     //文件头
        region_to_test.l_start = start_byte;
        region_to_test.l_len = SIZE_TO_TRY;
        region_to_test.l_pid = -1;
        printf("Testing F_RDLCK on region from %d to %d\n", start_byte, start_byte + SIZE_TO_TRY);

        /*test the lock for file again*/
        res = fcntl(file_desc, F_GETLK, &region_to_test);
        if(res == -1){
            fprintf(stderr, "F_GETLK failed\n");exit(EXIT_FAILURE);
        }
        //show_lock_info(&region_to_test);

        if(region_to_test.l_pid != -1){
            printf("Lock would fail . F_GETLK returned :\n");
            show_lock_info(&region_to_test);
        }else{
            printf("F_RDLCK - Lock would succeed\n");
        }
    }

    close(file_desc);
    return 0;
}

void show_lock_info(struct flock *to_show){
    printf("\tl_type %d, ", to_show -> l_type);
    printf("l_whence %d, ", to_show -> l_whence);
    printf("l_start %d, ", (int)to_show -> l_start);
    printf("l_len %d, ", (int)to_show -> l_len);
    printf("l_pid %d\n", to_show -> l_pid);
}
