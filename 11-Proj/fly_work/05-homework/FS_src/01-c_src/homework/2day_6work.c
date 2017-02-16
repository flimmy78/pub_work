#include <stdio.h>
#include <stdbool.h>

//判断n是否为素数
bool fun(int n)
{
	int i;
	for(i = 2; i < n;i++)
		if(n % i == 0)
			break;
	if(i < n)
		return false;
	else
		return true;
}

int main(void)
{
	int m;

	scanf("%d",&m);
	int i;

	for(i = 2; i <= m; i++)
		if(fun(i))
			printf("%d\t",i);
	printf("\n");

	return 0;
}
