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
#if 1
    fprintf(stdout,"sno:%d,name:%s,score:%f",st.sno,st.name,st.score); //向标准输出写数据
    printf("\n");
#else
    fprintf(fp,"sno:%d,name:%s,score:%f",st.sno,st.name,st.score); //向fp指向的文件中写数据
    //fflush(fp);
#endif
    //while(1);
    return 0;
}
