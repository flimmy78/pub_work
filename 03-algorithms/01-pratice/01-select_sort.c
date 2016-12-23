#include <stdio.h>

#define N 8
#define DEBUG_TEST

void select_sort(int a[], int n)
{
	int i,j;

	for(i = 0; i < n-1; i++)	//进行n-1轮选择
	{
		int min_index = i;
		for(j = i+1; j < n; j++)	//选出未排序的最小的数
		{
			if(a[j] < a[min_index])
			{
				min_index = j;
			}
		}
#ifdef DEBUG_TEST
		printf("第%d轮选择：a[min_index] = %d\ta[i] = %d\n",(i+1),a[min_index],a[i]);
#endif

		if(i != min_index)	//将第n小的数排在相应的位置
		{
			int tmp;
			tmp = a[i];
			a[i] = a[min_index];
			a[min_index] = tmp;
#ifdef DEBUG_TEST
			printf("    交换后：a[min_index] = %d\ta[i] = %d\n",a[min_index],a[i]);
#endif
		}
	}
}

#ifdef DEBUG_TEST
int main()
{
	int a[N]= {89, 100, 12, 56, 4, 789, 55, 456};
	int i;

	puts("排序前：");
	for(i = 0; i<N; i++)
		printf("%d  ",a[i]);
	puts("");

	select_sort(a, N);
	puts("排序后：");
	for(i = 0; i<N; i++)
		printf("%d  ",a[i]);
	puts("");

	return 0;
}
#endif
