/*******************************************************************
 *   > File Name: 04-copy_block.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jun  6 16:28:17 2017
 ******************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char block[1024];
    int in, out;
    int nread;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    while((nread = read(in, block, sizeof(block))) > 0){
        write(out, block, nread);
    }

    return 0;
}
