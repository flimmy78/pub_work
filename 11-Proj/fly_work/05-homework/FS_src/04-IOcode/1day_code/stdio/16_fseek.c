#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    FILE *fp;
    if(argc != 2){
	printf("Uage: %s [file_path]\n",argv[0]);
	exit(1);
    }
    fp = fopen(argv[1],"r+");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 
    char str[100];
    int ret;
    ret = ftell(fp);
    printf("ret = %d\n",ret);

    fseek(fp,3,SEEK_SET);    //修改当前的文件指针的位置
    bzero(str,100);
    fread(str,1,100,fp);
    printf("%s\n",str);
    ret = ftell(fp);
    printf("ret = %d\n",ret);  //获取当前指针的位置
    return 0;
}
