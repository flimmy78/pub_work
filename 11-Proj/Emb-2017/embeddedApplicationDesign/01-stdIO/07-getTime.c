/*******************************************************************
 *   > File Name: 07-getTime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 02 Sep 2017 10:15:07 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUF_LENGTH  64

int main(int argc, char* argv[])
{
    int n = 0;
    char buf[BUF_LENGTH];
    FILE *fps;
    time_t t;

    /*1.判断命令行参数*/
    if(argc < 2){
        sprintf(buf,"Usage : %s <file_name>\n", argv[0]);
        printf("%s", buf);
        return (-1);
    }

    /*2.打开文件*/
    if((fps = fopen(argv[1], "w")) == NULL){
        fprintf(stderr, "Fopen %s error :%s\n", argv[1], strerror(errno));
        return (-1);
    }

    /*2.每隔1秒，获得时间，写入文件，记录下来*/
    while(1){
        n ++;
        t = time(NULL);
        fprintf(fps, "Good Luck %4d : %s", n, ctime(&t));
        fprintf(stdout, "%4d\n", n);
        sleep(1);
        fflush(NULL);
    }

    fclose(fps);

    return 0;
}
