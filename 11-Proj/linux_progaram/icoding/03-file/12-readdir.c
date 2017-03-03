/*******************************************************************
 *   > File Name: 12-readdir.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 03 Mar 2017 02:28:40 PM CST
 ******************************************************************/
#if (0)
struct dirent *readdir(DIR *dirp);

struct dirent {
    ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* not an offset; see NOTES */
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
                                   by all filesystem types */
    char           d_name[256]; /* filename */
};

#endif

#include <stdio.h>
/*INC for readdir*/
#include <dirent.h>
/*INC for opendir*/
#include <sys/types.h>
#include <dirent.h>

#include <errno.h>

int main(int argc, char* argv[])
{
    DIR* dir;
    struct dirent *ptr;
    int i;

    /*获取目录名*/
    if(argc < 2){
        printf("Usage : %s <dir>\n",argv[0]);return -1;
    }
    
    /*打开目录*/
    if((dir = opendir(argv[1])) == NULL){
        perror("opendir err");return errno;
    }

    /*读取目录，输出目录下的文件名*/
    while((ptr = readdir(dir)) != NULL){
        printf("d_name : %s \n",ptr->d_name);
    }

    /*关闭目录*/
    close(dir);

    return 0;
}
