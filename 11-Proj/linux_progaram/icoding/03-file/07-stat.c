/*******************************************************************
 *   > File Name: 07-stat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 02:26:16 PM CST
 ******************************************************************/
#if (0)
/*获取文件的信息*/
int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);

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

#include <stdio.h>
/*include file for stat*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Usage: %s <filepath>\n",argv[0]);return (-1);
    }

    struct stat info;

    if((stat(argv[1], &info)) != 0){
        perror("stat file info err");return (-2);
    }

    printf("stat file info success\n");



    return 0;
}
