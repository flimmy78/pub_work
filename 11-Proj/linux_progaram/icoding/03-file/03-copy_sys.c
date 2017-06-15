/*******************************************************************
 *   > File Name: 03-copy_sys.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 06 Jun 2017 11:59:08 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//#define FILE_IN     "file.in"
#define FILE_OUT    "file.out"

int main(int argc, char* argv[])
{
    char c;
    int in, out;
    char *FILE_IN;

    //printf("argc = %d\n", argc);
    if(argc == 2){
        FILE_IN = argv[1];
    }else{
        FILE_IN = "file.in";
        printf("More usage : %s  <file.in_name> \n", argv[0]);
    }
    
    
    /*打开可读的源文件*/
    in = open(FILE_IN, O_RDONLY);
    
    /*已可读方式打开文件，不存在则创建；读、写权限，文件属主*/
    /*打开目标文件*/
    out = open(FILE_OUT, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    /*读完文件的所有字节，并将所有的字节全部写到新文件中*/
    while(read(in, &c, 1) == 1){
        write(out, &c ,1);
    }

    return 0;
}
