/*******************************************************************
 *   > File Name: 98-strerror.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Mar 2017 10:08:10 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    FILE *fp;

    if((fp = fopen("1.txt", "r")) == NULL){
        printf("fail to fopen :%s\n",(char *)strerror(errno));return (errno);
    }

    fclose(fp);
    

    return 0;
}
