#include <stdio.h>
#include <string.h>


int main(void)
{
	char str[22];
	int i;
/*
	for(i = 0;i < 5; i++)
		//str[i] = 'A'+i;
		scanf("%c",&str[i]);
	for(i = 0;i < 5; i++)
		printf("%c\t",str[i]);
	printf("\n");
*/
	//scanf("%s",str);	
	//str = "hello";   //err
	strcpy(str,"hello");   //字符数组赋值
	printf("%s\n",str);
	return 0;
}
