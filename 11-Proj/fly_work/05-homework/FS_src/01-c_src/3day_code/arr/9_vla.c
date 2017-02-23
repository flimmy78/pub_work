#include <stdio.h>

int main(void)
{
	int n,i;
	//n = 5;
	scanf("%d",&n);
	int a[n];

	for(i = 0; i < n; i++)
		a[i] = i+1;
	for(i = 0; i < n; i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
