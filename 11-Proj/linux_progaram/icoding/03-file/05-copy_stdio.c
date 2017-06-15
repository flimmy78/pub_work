/*******************************************************************
 *   > File Name: 05-copy_stdio.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Jun  6 17:33:45 2017
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int c;
    FILE *in , *out;

    in = fopen("file.in", "r");
    out = fopen("file.out", "w");

    while((c = fgetc(in)) != EOF)
        fputc(c, out);

    return 0;
}
