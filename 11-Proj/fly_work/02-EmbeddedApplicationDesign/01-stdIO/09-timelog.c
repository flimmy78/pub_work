/*******************************************************************
 *   > File Name: 09-timelog.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 14 Jan 2017 08:54:27 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 64

/*****************************************************************
 *获取系统时间、在程序中延时，流的格式输出
 *程序中每隔一秒读取一次系统时间并写入文件
 *打开文件→获取系统时间→写入时间→延时1s→返回第二部（获取系统时间）
 ****************************************************************/

int main(int argc, char* argv[])
{
    int n;
    char buf[N];

    FILE* fp;
    time_t t;

    if(argc < 2)
    {
        printf("Usage : %s <flie> \n",argv[0]);
        return (-1);
    }

    if((fp = fopen(argv[1],"w")) == NULL)
    {
        perror("Fail to fopen");
        return (-1);
    }

    int i = 0;
    while(1)
    {
        i++;
        time(&t);   //获取系统时间
        fprintf(fp,"%d : %s\n",i,ctime(&t));
        fflush(fp);
        sleep(1);
    }
    fclose(fp);

    return 0;
}
