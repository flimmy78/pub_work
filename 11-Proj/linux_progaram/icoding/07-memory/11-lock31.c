/*******************************************************************
 *   > File Name: 10-lock3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 25 Apr 2017 10:38:55 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define DELAY_TIMES     (6)

const char *test_file = "/tmp/test_lock";

int main(int argc, char* argv[])
{
    int file_desc;
    int byte_count;
    char *byte_to_write = "A";
    struct flock region_1;
    struct flock region_2;
    int res;
    
    /*open a file descriptor*/
    file_desc = open(test_file, O_RDWR | O_CREAT , 0666);
    if(!file_desc){
        fprintf(stderr, "Unable to open %s for read/write \n", test_file);
        exit(EXIT_FAILURE);
    }
    
    /*add data to file*/
    for(byte_count = 0; byte_count < 100; byte_count ++){
        (void)write(file_desc, byte_to_write, 1);
    }

    /*10~30bytes set to region_1, set F_RDLCK*/
    region_1.l_type = F_RDLCK;
    region_1.l_whence = SEEK_SET;
    region_1.l_start = 10;
    region_1.l_len = 20;

    /*40~50bytes set to region_2, set F_WRLCK*/
    region_2.l_type = F_WRLCK;
    region_2.l_whence = SEEK_SET;
    region_2.l_start = 40;
    region_2.l_len = 10;

    /*set the lock of file*/
    printf("Process %d locking file\n", getpid());
    res = fcntl(file_desc, F_SETLKW, &region_1);
    if(res == -1)
        fprintf(stderr, "Failed to lock region 1\n");
    res = fcntl(file_desc, F_SETLKW, &region_2);
    if(res == -1)
        fprintf(stderr, "Failed to lock region 2\n");
    //printf("%d region 1&2 to be locked\n",getpid());

    /*wait a little*/
    sleep(DELAY_TIMES);

    printf("Process %d closing file\n",getpid());
    close(file_desc);

    return 0;
}
