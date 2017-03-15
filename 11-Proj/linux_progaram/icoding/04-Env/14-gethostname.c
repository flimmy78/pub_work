/*******************************************************************
 *   > File Name: 14-gethostname.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 03:11:44 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>

//#define _GNU_SOURCE

int main(int argc, char* argv[])
{
#if 0
    char buf[128];
    memset(buf, 0, 128);
    
    gethostname(buf, 128);
    printf("%s\n",buf);
#endif
    struct utsname uts;

    uname(&uts);
    printf("%s\n%s\n%s\n%s\n%s\n",
            uts.sysname,
            uts.nodename,
            uts.release,
            uts.version,
            uts.machine/*,
            uts.domainname*/);

    return 0;
}
