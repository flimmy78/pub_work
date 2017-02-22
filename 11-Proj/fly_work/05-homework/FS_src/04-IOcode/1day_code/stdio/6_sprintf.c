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
    fp = fopen(argv[1],"w");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 
    
    struct student st  = {1003,"张飞",98.6}; 
    char str[100];

    //sprintf(str,"%d,%s,%f",st.sno,st.name,st.score); //向str指向的文件中写数据
    snprintf(str,100,"%d,%s,%f",st.sno,st.name,st.score); //向str指向的文件中写数据
    printf("%s\n",str);
    return 0;
}
