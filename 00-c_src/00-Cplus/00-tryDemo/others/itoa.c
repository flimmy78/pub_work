#include <stdio.h>

#if 1
void itoa(int a)
{
	int i = 0;
	char str[15];

	if(a == 0)
	{
		str[0] = '0';
		printf("str[%d] = '%c' ,a = %d\n",i,str[i],a);
	}
	else
	{
		for(i = 0; a > 0; i++)
		{
			str[i] = a % 10;
			a/=10;
#ifndef DEBUG
			printf("str[%d] = '%c' , a = %d\n",i,str[i] + '0',a);
#endif
		}
	}
	str[i] = '\0';

}
#else
void itoa(int a)
{
	int i = 0;
	char str[100];

	do{
		str[i] = a % 10;
		a/=10;
		printf("str[%d] = '%c' , a = %d\n",i,str[i]+48,a);
		i++;
	}while(a > 0);
}
#endif

int main(void)
{	
	int a;
	while(1)
	{
		printf("Pls input a : ");	
		scanf("%d",&a);
		itoa(a);
	}

	return 0;
}
