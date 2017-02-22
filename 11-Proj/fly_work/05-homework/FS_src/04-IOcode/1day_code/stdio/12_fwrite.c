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
    if(argc != 2){
	printf("Uage: %s [file_path]\n",argv[0]);
	exit(1);
    }
    fp = fopen(argv[1],"w+");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 

#if 0
    int arr[5] = {1,2,3,4,5};
    fwrite(arr,sizeof(int),5,fp);   //将数组arr中的5个整型数写入fp指向的文件中

    char str[] = "hello world";
    fwrite(str,1,11,fp);   //将字符串hello world写入fp指向的文件中
#else
    struct student st[4] = {{1001,"奥巴码",98.6},\
			    {1002,"习主席",99.9},\
			    {1003,"萨达姆",97.5},\
			    {1004,"赵云",93.4}};
    int ret;
    ret = fwrite(st,sizeof(struct student),4,fp);   //向fp指向的文件中写4个结果体
    printf("ret = %d\n",ret);
#endif
    return 0;
}
