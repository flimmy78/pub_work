#include <stdio.h>
#include <string.h>

int main(void)
{
	int len;

	char STR[] = "helloworld";
	
	printf("字符串：%s\n",STR);
	len = sizeof(STR);
	printf("在内存中的长度%d\n",len);
	len = strlen(STR);
	printf("字符串的长度%d\n",len);
	
	return 0;
}
