#include <stdio.h>

#define N 8

void quicksort(int a[],int low,int high);
int quick_pass(int a[],int i,int j);
void show(int a[]);
int main(void)
{
    int a[N] = {50,36,66,76,36,12,25,95};

    show(a);
    quicksort(a,0,N-1);
    return 0;
}

int quick_pass(int a[],int i,int j)
{
    int tmp;
    tmp = a[i];
    while(i < j){
	while(i < j && tmp <= a[j])
	    j--;
	if(i < j)
	    a[i] = a[j];
	while(i < j && tmp > a[i])
	    i++;
	if(i < j)
	    a[j] = a[i];
    }

    a[i] = tmp;
    show(a);
    return i;
}

void quicksort(int a[],int low,int high)
{
    int mid;
   if(low < high){
	mid = quick_pass(a,low,high); //一趟快速排序
	quicksort(a,low,mid-1);  
	quicksort(a,mid+1,high);
   } 
}
void show(int a[])
{
    int i;

    for(i = 0; i < N;i++)
	printf("%d\t",a[i]);
    printf("\n");
}
