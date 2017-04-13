#include <stdio.h>

#pragma pack(push)
#pragma pack(4)
struct test
{
	char m1;
	double m2;
	int m3;

};
#pragma pack(pop)

int main(void)
{
	int i,j,k,l;
	i = sizeof(char);
	j = sizeof(double);
	k = sizeof(int);
	l = i + j + k;

	int m;
	m = sizeof(struct test);
	
	printf("m1=%d\tm2=%d\tm3=%d\n",i,j,k);
	printf("对齐前：%d\n对齐后：%d\n",l,m);

	return 0;
}
