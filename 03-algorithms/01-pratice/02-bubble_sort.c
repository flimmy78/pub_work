#include <stdio.h>
#include <stdbool.h>

#define N 8
#define DEBUG_TEST
//#define DEBUG_TEST_

void bubble_sort(int a[], int n);
void bubble_sort_better(int a[], int n);
void printf_arr(int a[], int n);

#ifdef DEBUG_TEST
int main(void)
{
	int a[N] = {99, 55, 12, 45, 23, 11, 77, 88};

	puts("排序前");
#if (0)
    int i;
	for(i = 0; i < N; i++)
	{
		printf("%d  ",a[i]);
	}
	puts("");
#else
	printf_arr(a,N);
#endif
	
#if 0
	bubble_sort(a,N);
#else
	bubble_sort_better(a,N);
#endif

	puts("排序后");
	printf_arr(a,N);

	return 0;
}
#endif

/* 冒泡排序法 */
void bubble_sort(int a[], int n)
{
	static int i, j;

	for(i = 0; i< n-1; i++)	//进行n-1轮比较
	{
		printf("\t第%d轮排序: %d\n",(i+1),a[0]);
		for(j = 0; j < n-1-i; j++)	//与n-1-i个数进行比较
		{
			if(a[j] > a[j+1])		//比较大的数往后移动
			{
#ifdef DEBUG_TEST_
				printf("交换前：a[%d] = %d\ta[%d] = %d\n",j,a[j],j+1,a[j+1]);
#endif
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
#ifdef DEBUG_TEST_
				printf("\t交换后：a[%d] = %d\ta[%d] = %d\n",j,a[j],j+1,a[j+1]);
#endif
			}
#if (1)
			printf_arr(a,n);
#endif
		}
#ifdef DEBUG_TEST_
		printf("第%d轮排序后:",(i+1));
		printf_arr(a,n);
#endif
	}
}

/* 冒泡排序法（改进版） */
void bubble_sort_better(int a[], int n)
{
	int i, j;

	for(i = 0; i<(n-1); i++)	//进行n-1轮排序
	{
		printf("\t第%d轮排序: %d\n",(i+1),a[0]);
		bool isSorted = true;
		for(j = 0; j<(n-1-i); j++)
		{
			if(a[j] > a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				isSorted = false;
			}
			printf_arr(a,N);
		}

		/* */
		if(isSorted)
		{
			break;
		}
	}

}

/* 打印数组 */
void printf_arr(int a[], int n)
{
	int i;
	for(i = 0; i<N ; i++)
	{
		printf("%d  ",a[i]);
	}
	puts("");
}
