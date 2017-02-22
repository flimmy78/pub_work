#include <stdio.h>
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
    fread(str,1,3,fp);
    ret = ftell(fp);
    printf("ret = %d\n",ret);  //获取当前指针的位置
    return 0;
}
