/*******************************************************************
 *   > File Name: 03-unlink.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 16 Jan 2017 04:53:21 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage : %s namepath\n",argv[0]);
        return 0;
    }

    int ret = 0;
    ret = unlink(argv[1]);
    if(ret != 0)
    {
        printf("Unlink %s err : %s\n",argv[1],strerror(errno));
        return (-1);
    }
    return 0;
}
