#include <stdio.h>
#include <string.h>

int main(void)
{
	/*部分初始化*/
	/*
	   int a[10] = {1,2,3,4,5};
	   printf("sizeof(a) = %d\n",sizeof(a));
	 */
	//char str[10] = {'H','e','l','l','o','\0'};
	//char str[10] = {"Hello"};
	char str[10] = "Hello";
	printf("sizeof(str) = %d\n",sizeof(str));	//字符串数组的长度
	printf("strlen(str) = %d\n",strlen(str));	//字符数组中的字符串的实际长度
	printf("strlen(\"hello\") = %d\n",strlen("hello"));		//字符串的实际长度

	return 0;
}
