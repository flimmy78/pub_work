#include <stdio.h>
#include <string.h>

void my_strcat(char str1[],char str2[])
{
	int len = strlen(str1);
	int i;
	for(i = 0; str2[i] != '\0'; i++)
		str1[len+i] = str2[i]; 
	str1[len+i] = '\0';
}

int main(void)
{
	char str1[100] = "hello",str2[100] = "world";

	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	my_strcat(str1,str2);
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	return 0;
}
