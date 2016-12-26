#include <stdio.h>

#if 0
int Fdigit_Tgroup(int i, int j, int k)
#else
int Ndigit_Tgroup(int N)
#endif
{
	int i,j,k;
	int count = 1;
	for(i = 1; i<=N; i++)
	{
		for(j = 1; j<=N; j++)
		{
			for(k = 1; k<=N; k++)
			{
				if(i != j && i != k && j != k)
				{
					printf("%2d : %d %d %d\n",count++,i,j,k);
				}
			}
		}
	}

	return count;
}

int main(void)
{
	Ndigit_Tgroup(4);

	return 0;
}
