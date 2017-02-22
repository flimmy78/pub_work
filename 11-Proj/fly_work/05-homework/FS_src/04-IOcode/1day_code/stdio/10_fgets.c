#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main(int argc,char **argv)
{
    FILE *fp;
    char buf[SIZE];
    if(argc != 2){
	printf("Uage: %s [file_path]\n",argv[0]);
	exit(1);
    }
    fp = fopen(argv[1],"r");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 
    
    //一次读一行
    //while(fgets(buf,SIZE,stdin) != NULL)   //从标准输入读数据
    while(fgets(buf,SIZE,fp) != NULL)   //从指定的文件中读数据
	printf("%s",buf);
    return 0;
}
