#include <stdio.h>
#include <stdlib.h>

struct student{
    int sno;
    char name[20];
    float score;
};

int main(int argc,char **argv)
{
    FILE *fp;
    //判断命令行是否有输入参数
    if(argc != 2){
	printf("Uage: %s [file_path]\n",argv[0]);
	exit(1);
    }
    //打开文件
    fp = fopen(argv[1],"r");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 
    
    //struct student st = {1001,"peter",95.6};
#if 0
    char str[] = "1001 peter 95.6";
    struct student ss;
    sscanf(str,"%d%s%f",&ss.sno,ss.name,&ss.score); 
   printf("%d\t%s\t%f\n",ss.sno,ss.name,ss.score);
#else
    char time[] = "9:40";
    int h,m;
    sscanf(time,"%d:%d",&h,&m);
    printf("h = %d,m = %d\n",h,m);
#endif
    return 0;
}
