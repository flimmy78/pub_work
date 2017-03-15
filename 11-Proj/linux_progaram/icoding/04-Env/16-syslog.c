/*******************************************************************
 *   > File Name: 16-syslog.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 15 Mar 2017 04:17:13 PM CST
 ******************************************************************/

#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *f;

    f = fopen("not_here", "r");
    if(!f)
        syslog(LOG_EMERG|LOG_USER, "oops - %m\n");

    return 0;
}
