#include <stdio.h>
#include <string.h>

#if (0)
#include <string.h>
void *memset(void *s,int c, size_t n);
//function:将s所指向的某一块内存中的前n个字节的内容全部设置为c指定的ASCII值
//return:返回内存s区域的指针
#endif

#define CH 'A'

int memset_test(void)
{
	char str_src[10];
//	char str_dst[20];

	memset(str_src,CH,sizeof(str_src));
	printf("%s\n",str_src);

	return 0;
}

int main(void)
{
	memset_test();

	return 0;
}
