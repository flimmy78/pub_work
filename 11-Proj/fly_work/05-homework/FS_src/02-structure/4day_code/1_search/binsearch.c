#include <stdio.h>

#define N 12

int binsearch(int a[],int key);
int show(int a[]);
int main(void)
{
    int key,ret;
    int a[N] = {3,12,18,20,32,55,60,68,80,86,90,100};
    char ch;

    show(a);
    while(1){
	printf("请输入要查找的记录的关键字:");
	scanf("%d",&key);
	ret = binsearch(a,key);
	if(ret != -1){   //查找成功
	    printf("查找成功，要查找的记录的下标为%d\n",ret);
	}else{	//查找失败
	    printf("查找失败，关键字为%d的记录不存在!\n",key);
	}
	printf("是否继续查找(Y/y)？");
	while(getchar() != '\n');   //清空缓冲区
	scanf("%c",&ch);
	if(ch != 'Y' && ch != 'y')
	    break;
    }	
    return 0;
}

int binsearch(int a[],int key)
{
    int low,high,mid;
    for(low = 0,high = N-1;low <= high; ){
	mid = (low + high) / 2;
	if(key == a[mid])
	    return mid;
	else if(key > a[mid])
	    low = mid + 1;
	else
	    high = mid -1;
    }
    return -1;
}
int show(int a[])
{
    int i;
    for(i = 0; i < N; i++)
	printf("%d\t",a[i]);
    printf("\n");
}
