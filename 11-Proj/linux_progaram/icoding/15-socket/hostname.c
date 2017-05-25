/*******************************************************************
 *   > File Name: hostname.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 25 May 2017 10:44:51 AM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char name[256];
    int res;

    res = gethostname(name, 255);
    if(res != 0){
        perror("gethostname");exit(1);
    }

    printf("hostname :%s\n", name);

    return 0;
}
