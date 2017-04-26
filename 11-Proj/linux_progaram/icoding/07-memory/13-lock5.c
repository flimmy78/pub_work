/*******************************************************************
 *   > File Name: 13-lock5.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 25 Apr 2017 03:33:30 PM CST
 ******************************************************************/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

const char *test_file = "/tmp/test_lock";

int main()
{
    int file_desc;
    struct flock region_to_lock;
    int res;
    
    /*open a file descriptor*/
    file_desc = open(test_file , O_RDWR | O_CREAT, 0666);
    if(!file_desc){
        fprintf(stderr, "Unable to open %s for read/write\n", test_file);exit(EXIT_FAILURE);
    }
    
    /* F_RDLCK  10~15 */
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 10;
    region_to_lock.l_len = 5;
    printf("Process %d, trying F_RDLCK, region %d to %d\n", getpid(),
            (int)region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d - failed to lock region\n", getpid());
    }else{
        printf("Process %d - obtained lock region\n", getpid());
    }
    
    /* F_UNLCK 10~15 */
    region_to_lock.l_type = F_UNLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 10;
    region_to_lock.l_len = 5;
    printf("Process %d, trying F_UNLCK, region %d to %d\n", getpid(),
            (int)region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d -failed to unlock region\n", getpid());
    }else{
        printf("Process %d - unlocked region\n", getpid());
    }
        
    /* F_UNLCK 0~50 */
    region_to_lock.l_type = F_UNLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 0;
    region_to_lock.l_len = 50;
    printf("Process %d, trying F_UNLCK, region %d to %d\n", getpid(),\
            (int)region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d -failed to unlock region\n", getpid());
    }else{
        printf("Process %d - unlocked region\n", getpid());
    }
    
    /* F_WRLCK 16~21 */
    region_to_lock.l_type = F_WRLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 16;
    region_to_lock.l_len = 5;
    printf("Process %d, trying F_WRLCK, region %d to %d\n", getpid(),\
            (int)region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d - failed to unlock region\n", getpid());
    }else{
        printf("Process %d - unlocked region\n", getpid());
    }

    /* F_RDLCK 40~50 */
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 40;
    region_to_lock.l_len = 10;
    printf("Process %d, trying F_RDLCK, region %d to %d \n", getpid(),\
            (int)region_to_lock.l_start, (int)(region_to_lock.l_start + region_to_lock.l_len));
    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if(res == -1){
        printf("Process %d -failed to unlock region\n", getpid());
    }else{
        printf("Process %d - unlocked region\n", getpid());
    }

    return 0;
}
