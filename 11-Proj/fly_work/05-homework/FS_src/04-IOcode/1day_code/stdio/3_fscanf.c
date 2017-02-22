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
    
    struct student st; 
    /*
    int a;
    float b;
    fscanf(fp,"a=%d,b=%f",&a,&b);
    printf("a=%d,b=%f\n",a,b);
    */
#if 0
    fscanf(stdin,"%d%s%f",&st.sno,st.name,&st.score); //从标准输入中读数据
#else
    fscanf(fp,"%d%s%f",&st.sno,st.name,&st.score); //从fp指向的文件中读数据
#endif
    printf("%d\t%s\t%f\n",st.sno,st.name,st.score);
    return 0;
}
