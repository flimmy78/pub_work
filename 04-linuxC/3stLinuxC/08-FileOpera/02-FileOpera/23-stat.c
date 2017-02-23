/*******************************************************************
 *   > File Name: 23-stat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 23 Feb 2017 03:09:25 PM CST
 ******************************************************************/
#if (0)
/*将参数 file_name 所指的文件状态，复制到参数 buf 所
 * 指的结构中*/
//执行成功则返回 0，失败返回-1，错误代码存于 errno
int stat(const char *path, struct stat *buf);


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

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdlib.h>

#include <time.h>

int main(int argc, char* argv[])
{
    struct stat sb;/*定义一个文件状态结构体数据变量*/

    if(argc != 2){/*判断有无输入文件路径名*/
        printf("Usage :%s <pathname>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    /*获取文件状态数据*/
    if((stat(argv[1], &sb)) == -1){
        perror("stat");
        exit(EXIT_FAILURE);
    }

    puts("File type :");
    
    switch(sb.st_mode & S_IFMT){
        case S_IFBLK: printf("block device\n");     break;
        case S_IFCHR: printf("character device\n"); break;
        case S_IFDIR: printf("directory\n");        break;
        case S_IFIFO: printf("FIFO/pipe\n");        break;
        case S_IFLNK: printf("symlink\n");          break;
        case S_IFREG: printf("regular file\n");     break;
        case S_IFSOCK:printf("socket\n");           break;
        default:      printf("unknown?\n");         break;
    }

    printf("I-node number:            %ld\n",(long)sb.st_ino);
    printf("Mode:                     %lo (octal)\n",(unsigned long)sb.st_mode);
    printf("Link count:               %ld\n",(long)sb.st_nlink);
    printf("Ownership:                UID = %ld  GID = %ld\n",(long)sb.st_uid, (long)sb.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",(long)sb.st_blksize);
    printf("File size :               %lld bytes\n",(long long)sb.st_size);
    printf("Blocks allocated:         %lld\n ",(long long)sb.st_blocks);

    printf("Last status change:       %s",ctime(&sb.st_atime));
    printf("Last file access  :       %s",ctime(&sb.st_mtime));
    printf("Last file modification:   %s",ctime(&sb.st_ctime));

    return 0;
}
