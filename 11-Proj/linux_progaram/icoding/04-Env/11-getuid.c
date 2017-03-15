/*******************************************************************
 *   > File Name: 11-getuid.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 02:21:08 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int uid, euid;
    uid = getuid(), euid = geteuid();

    printf("uid = %d\teuid = %d\n",uid, euid);
    
    int id;
    id = (euid << 8) + uid;
    printf("id = %d\n",id);
    printf("login :%s\n",getlogin());

    return 0;
}
