#include <stdio.h>
#include <string.h>

int main(void)
{
	char dst[128];
	char *src = "ABCDEFGHIJ1234567890";
	
	printf("src : %s,共有%d个字符！\n",src,strlen(src));
	while(1)
	{
		size_t n;
		printf("Pls Input :");
		scanf("%d",&n);
		strncpy(dst,src,n);
		printf("dst : %s,共有%d个字符，占有%d个字节！\n",dst,strlen(dst),sizeof(dst));
		memset(dst,0,sizeof(dst));
	}

	return 0;
}
