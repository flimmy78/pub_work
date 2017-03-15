/*******************************************************************
 *   > File Name: 15-gethosttid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 03:36:04 PM CST
 ******************************************************************/
#if (0)
long gethostid(void);
#endif

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("hostid :%ld\n",gethostid());
    return 0;
}
