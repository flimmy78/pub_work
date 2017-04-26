/*******************************************************************
 *   > File Name: 01-execlp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 26 Apr 2017 03:12:08 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Running ps with execlp\n");
    //execlp("/bin/ps", "ps", "ax", NULL);
    execlp("/bin/ps", "ps", "ax", (char*)0);
    printf("Done.\n");
    
    int i = 0;
    for(i = 0; i < 10; i++){
        printf("%d loop\n",i);
    }

    return 0;
}
