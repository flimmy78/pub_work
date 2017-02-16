//15、编写一个函数，输入一个十进制数，输出对应的十六进制数。（不能用printf的%x格式说明符）
#include <stdio.h>

void fun(int n){
	char str[] = "0123456789ABCDEF";
	char tmp[10];
	int i;
	for(i = 0;n != 0;i++){
		tmp[i] = str[n%16];
		n /= 16;
	}
	for(--i;i>=0;i--)
		printf("%c",tmp[i]);
	printf("\n");
}

int main(void)
{
	int n;
	scanf("%d",&n);
	fun(n);

	return 0;
}
