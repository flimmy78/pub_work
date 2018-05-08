/*******************************************************************
 *   > File Name: 284-codeSerialNumber.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月27日 星期五 22时21分39秒
 ******************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //char *ysn;
    //char *sn;
    char ysn[128]={0};
    char sn[128] = "1001-1618-2903";
    scanf("%s",ysn);
    if(!strncmp(ysn, sn, strlen(sn)))
        printf("register succeed\n");
    else
        printf("register lose\n");

    return 0;
}
