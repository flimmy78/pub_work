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
    fp = fopen(argv[1],"r+");
    if(NULL == fp){
	perror("fopen");
	exit(1);
    } 

#if 0
    int arr[5],i;
    fread(arr,sizeof(int),5,fp);
    for(i = 0; i < 5; i++)
	printf("%d\n",arr[i]);

    char str[100];
    fread(str,1,100,fp);   //从fp指向的文件中读数据
    printf("%s\n",str);
#else
    struct student st[4];
    int i,ret;
    ret = fread(st,sizeof(struct student),4,fp);   //从fp指向的文件中读4个结构体对象
    printf("ret = %d\n",ret);
    for(i = 0; i < 4; i++)
	printf("%d\t%s\t%f\n",st[i].sno,st[i].name,st[i].score);

#endif
    return 0;
}
