/*******************************************************************
 *   > File Name: 03-copy_sys.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 05 Jun 2017 05:39:42 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char c;
    int in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSE | S_IWUSE);
    
    while(read(in, &c, 1) == 1){
        write(out, &c, 1);
    }

    return 0;
}
