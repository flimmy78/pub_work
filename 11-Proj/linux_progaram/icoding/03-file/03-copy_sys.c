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

int main(int argc, char* argv[])
{
    char c;
    int in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    while(read(in, &c, 1) == 1){
        write(out, &c ,1);
    }

    return 0;
}
