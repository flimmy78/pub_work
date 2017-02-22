/*
    每隔一秒钟向文件中写入一条时间信息
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(int argc,char ** argv)
{
    FILE *fp;
    int count = 0;
    char buf[SIZE];
    time_t tm;

    if(argc != 2){
	fprintf(stderr,"Usage: %s [file_path]\n",argv[0]);
	exit(1);
    }

    if((fp = fopen(argv[1],"a+")) == NULL){
	perror("fopen");
	exit(1);
    }
    
    while(fgets(buf,SIZE,fp) != NULL) count++;   //获取文件中已写的时间条数
    
    while(1){
	time(&tm);
	bzero(buf,SIZE);
	sprintf(buf,"%d:%s",count++,ctime(&tm));
	fputs(buf,fp);   //向文件中写入一条时间信息 
	fprintf(stdout,"%s",buf);   //向屏幕上打印该条时间信息
	fflush(fp);
	sleep(1);
    }
    return 0;
}
