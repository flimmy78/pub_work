#include <stdio.h>
#include <string.h>


int main(void)
{
	/*
	int a[10] = {1,2,3,4,5};
	printf("sizeof(a) = %d\n",sizeof(a));
	*/
	//char str[10] = {'h','e','l','l','o','\0'};
	//char str[10] = {"hello"};
	char str[10] = "hello";
	printf("sizeof(str) = %d\n",sizeof(str));	//字符数组的长度
	printf("strlen(str) = %d\n",strlen(str));   //字符数组中的字符串实际长度
	printf("strlen(\"hello\") = %d\n",strlen("hello")); //字符串的实际长度

	return 0;
}
