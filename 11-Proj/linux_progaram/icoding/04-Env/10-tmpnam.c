/*******************************************************************
 *   > File Name: 10-tmpnam.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 01:29:18 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;

    filename = tmpnam(tmpname);//is dangerous, better use `mkstemp' or `mkdtemp'
    //filename = mktemp(tmpname);//is dangerous, better use `mkstemp' or `mkdtemp'

    printf("Temporary file name is :%s\n",filename);
    tmpfp = tmpfile();
    if(tmpfp)
        printf("Opened  a temporary file OK\n");
    else
        perror("tmpfile");
    
    system("clear");
    for(;;);
    return 0;
}
