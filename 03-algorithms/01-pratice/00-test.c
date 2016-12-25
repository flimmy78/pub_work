#include <stdio.h>
#include <stdbool.h>

#define N 8
#define DEBUG_TEST

void bubble_sort(int a[], int n);
void printf_arr(int a[], int n);

#ifdef DEBUG_TEST
int main(void)
{
	int a[N] = {12, 99, 45, 66, 88, 55, 23, 11};
	printf_arr(a,N);

	bubble_sort(a,N);
	printf_arr(a,N);
	
	return 0;
}	
#endif

void bubble_sort(int a[], int n)
{
	int i, j;

	/* 对n-1个数进行排序 */
	for(i = 0; i < (n-1); i++)
	{
		bool isSorted = true;
		/* 对第i位数与未排序的数进行比较 */
		for(j = 0; j < (n-1-i); j++)
		{
#if (1)
			if(a[j] < a[j+1])
			{
				int tmp;
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				isSorted = false;
			}
#endif
		}
		if(isSorted)
			break;
	}
}

void printf_arr(int a[], int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%d  ",a[i]);
	}
	puts("");
}
