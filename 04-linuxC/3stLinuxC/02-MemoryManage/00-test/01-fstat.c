/*******************************************************************
 *   > File Name: 01-fstat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 11:55:14 AM CST
 ******************************************************************/

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <time.h>

#if (0)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int fstat(int fd, struct stat *buf);


struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
#endif

int main(int argc, char* argv[])
{
    int fd;
    struct stat fs;

    if(argc < 2)
    {
        printf("Usage :%s filepathname\n",argv[0]);
        return (-1);
    }

    fd = open(argv[1] , O_RDONLY);
    if(fd < 0)
    {
        perror("fail to open");
        return (-1);
    }

    fstat(fd, &fs);
    
    printf("st_dev:    %d\n",fs.st_dev);
    printf("st_ino:    %ld\n",fs.st_ino);
    printf("st_mode:   %d\n",fs.st_mode);
    printf("st_nlink:  %d\n",fs.st_nlink);
    printf("st_uid:    %d\n",fs.st_uid);
    printf("st_gid:    %d\n",fs.st_gid);
    printf("st_rdev:   %d\n",fs.st_rdev);
    printf("st_size:   %ld\n",fs.st_size);
    printf("st_blksize:%ld\n",fs.st_blksize);
    printf("st_blocks: %ld\n",fs.st_blocks);
    printf("st_atime:  %s",ctime(&fs.st_atime));
    printf("st_mtime:  %s",ctime(&fs.st_mtime));
    printf("st_ctime:  %s",ctime(&fs.st_ctime));
   

    close(fd);

    return 0;
}
