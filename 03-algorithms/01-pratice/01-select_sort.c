#include <stdio.h>
#include <stdlib.h>

#define N 8

void select_sort(int a[], int n)
{
	int i,j;
	for(i = 0; i < n-1; i++)	//进行N-1轮选择
	{
		int min_index = i;	//假定最小数的下标为i
		for(j = i+1; j<n; j++)
		{
			if(a[j] < a[min_index])
			{
				min_index = j;
			}
		}

		if(i != min_index)
		{
			int tmp = a[i];
			a[i] = a[min_index];
			a[min_index] = tmp;
		}
	}
}

int main()
{
	int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};

	select_sort(num, N);

	int i;
	for(i = 0; i<N ;i++)
		printf("%d  ",num[i]);
	printf("\n");

	return 0;
}
