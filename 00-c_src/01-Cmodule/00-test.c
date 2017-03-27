/*******************************************************************
 *   > File Name: 00-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 06:53:31 PM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
#if (0)
    int diffVal;
    diffVal = atoi(argv[1]);

    int val1 = 100, val2 = 200;
    int ret;

    ret = (val1 > val2 && val1 - val2 > diffVal || val2 >val1 && val2 -val1 > diffVal);
    printf("ret = %d\n",ret);

    char HWaddr[] = "00:0c:29:37:e6:24";
    int ret;
    ret = strlen(HWaddr);
    printf("ret = %d\n",ret);
#else
    char IP[] = "192.168.1.170";
    in_addr_t ret;
    ret = inet_addr(IP);
    printf("%x\n",ret);
#endif

    return 0;
}
