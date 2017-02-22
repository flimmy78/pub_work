#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    char name[100];
    printf("%s\n",tmpnam(name));   // 调用tmpnam()让系统分配一个唯一的临时文件名给该程序 
    printf("%s\n",name);
    return 0;
}
