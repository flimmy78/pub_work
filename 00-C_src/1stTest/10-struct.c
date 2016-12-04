#include <stdio.h>

int main(void)
{
	struct stu{
		char sex;
		int length;
		char name[10];
	};

	struct stu STU;
	STU = {'男',170,"小明"};

	int  datalength = sizeof(STU);
	printf("datalength = %d\n",datalength);
	
	return 0;
}
