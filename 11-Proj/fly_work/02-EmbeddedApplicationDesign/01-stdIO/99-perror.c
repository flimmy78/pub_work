/*******************************************************************
 *   > File Name: 99-perror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Mar 2017 11:33:09 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    FILE *fp;

    if((fp = fopen("1.txt", "r")) == NULL){
        perror("fopen 1.txt err");//exit(errno);
    }

    if(fclose(fp) != 0){
        perror("fclose err");exit(errno);
    }

    return 0;
}
