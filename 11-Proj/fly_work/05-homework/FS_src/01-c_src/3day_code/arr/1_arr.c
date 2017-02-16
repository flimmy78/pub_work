#include <stdio.h>


int main(void)
{
	int a[] = {1,2,3,4,5,6};   //完全初始化
	printf("sizeof(a) = %d\n",sizeof(a));
	//char str[] = {'h','e','l','l','o','w','o','r','l','d','\0'};
	char str[] = "hello";
	printf("%s\n",str);
	printf("sizeof(str) = %d\n",sizeof(str));
}
