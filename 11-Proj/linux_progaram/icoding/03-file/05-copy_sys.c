/*******************************************************************
 *   > File Name: 05-copy_sys.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 02 Mar 2017 11:39:26 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BLOCKSIZE 1024*10

int main(int argc, char* argv[])
{
    char c[BLOCKSIZE];
    int in, out;
    int nread;

    if(argc < 2){
        printf("Usage :%s <out_file_path>\n",argv[0]);return (-1);
    }

    if((in = open(argv[1], O_RDONLY)) < 0){
        perror("open err");return errno;
    }
    if((out = open("file.out", O_WRONLY|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR)) < 0){
        perror("open err");return errno;
    }

    while((nread = read(in, &c, BLOCKSIZE)) > 0){
        if((write(out, &c, nread)) != nread){
            perror("write err");return errno;
        }
    }

    return 0;
}
