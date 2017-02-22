#include <stdio.h>

int main(void)
{
	int a[] = {1,2,3,4,5,6};	//完全初始化
	printf("sizeof(a) = %d\n",sizeof(a));

	int i = 0;
	for(i = 0; i < (sizeof(a)/sizeof(int)); i++)
	{
		printf("a[%d] = %d\t",i,a[i]);
	}
	printf("\n");

	//char str[] = {'H','e','l','l','o','W','o','r','l','d'};
	char str[] = "HelloWorld";
	printf("%s\n",str);
	printf("sizeof(str) = %d\n",sizeof(str));

	return 0;
}
