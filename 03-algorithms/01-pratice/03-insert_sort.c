#include <stdio.h>
#include <stdlib.h>

#define N 8

void printf_arr(int a[], int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		printf("%d  ",a[i]);
	}
	puts("");
}

void insert_sort(int a[], int n)
{
	int i;
	for(i = 1; i<n; i++)
	{
		int j = 0;
		while(a[j] < a[i] && (j<i))
		{
			j++;
		}

		if(i != j)
		{
			int tmp = a[i];
			int k;
			for(k = i; k>j;k--)
			{
				a[k] = a[k-1];
			}
			a[j] =tmp;
		}
	}
}

int main()
{
	int num[N] = {89, 38, 11, 78, 96, 44, 19, 25};

	printf_arr(num,N);
	insert_sort(num, N);

	int i;
	for(i=0; i<N; i++)
	{
		printf("%d  ",num[i]);
	}
	puts("");

	return 0;
}
