/*******************************************************************
 *   > File Name: 01-perror.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Fri 13 Jan 2017 11:05:33 PM CST
 ******************************************************************/

#include <stdio.h>
#include <errno.h>

#define FILEPATH "./1.txt"

int main(void)
{
    FILE* fp;   //定义流指针

    if((fp = fopen(FILEPATH,"r")) == NULL)
    {
        perror("Fail to open");
        printf("Errno %d\n",errno);
        return (-1);
    }
    else
    {
        printf("(%d) Open %s OK\n",__LINE__,FILEPATH);
        printf("FILE_POINTER is %p\n",fp);
    }

    fclose(fp);

    return 0;
}
