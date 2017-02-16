#include <stdio.h>

#define N 8

void binsort(int a[]);
void show(int a[],int n);
int main(void)
{
    int a[N] = {50,36,66,76,95,12,25,36};

    show(a,N-1);
    binsort(a);
    return 0;
}

void binsort(int a[])
{
    int j,i;
    int tmp,low,high,mid;

    for(i = 1; i < N; i++){
	tmp = a[i];
	//用折半查找寻找tmp的位置
	for(low = 0,high = i-1;low <= high;){
	    mid = (low + high) / 2;
	    if(tmp < a[mid])
		high = mid - 1;
	    else
		low = mid + 1;
	}
	//移动low到i之间的记录
	for(j = i; j > low; j--)
	    a[j] = a[j-1];
	a[low] = tmp;  //将tmp插入到low的位置
	show(a,i);
    }
}
void show(int a[],int n)
{
    int i;

    for(i = 0; i <= n;i ++)
	printf("%d\t",a[i]);
    printf("\n");
}
