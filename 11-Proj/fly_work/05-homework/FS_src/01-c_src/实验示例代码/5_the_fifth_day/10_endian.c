#include <stdio.h>

int little_endian(char ch)
{
	if(ch == 0x78)
		return 1; //little endian
	else
		return 0; //big endian
}

int main(void)
{
    int i=0x12345678;
    char *p = (char *)&i;
    // 从执行结果来看，x86架构的处理器用的是小端模式
    // 记忆：小(地址小)对小(位权小)，则小端，否则是大端。
	if(little_endian(*p) == 1){
		printf("little endian.\n");
	}
	else{
		printf("big endian.\n");
	}
    return 0;
}
