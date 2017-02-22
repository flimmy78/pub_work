#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fun(int size)
{
	char *str;	
	str = (char*)malloc(size);   //申请堆空间
	if(NULL == str){
		printf("malloc failed!\n");
		exit(1);
	}
	strcpy(str,"hello world");
	return str;
}
int main(void)
{
	char *str;

	str = fun(20);
	printf("%s\n",str);

	free(str);   //释放堆空间
	return 0;
}
