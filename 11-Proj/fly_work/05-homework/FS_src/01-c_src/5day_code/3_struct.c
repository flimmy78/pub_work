#include <stdio.h>
#include <string.h>

struct student{
	int sno;
	char name[20];
	float high;
	float score;
};

int main(void)
{
	struct student st1 = {1001,"刘德华",1.80,99.9};  //完全初始化
	struct student st2;

	st2.sno = 1002;
	strcpy(st2.name,"peter");
	st2.high = 1.89;
	st2.score = 98.4;
	printf("%d\t%s\t%.2f\t%.2f\n",st1.sno,st1.name,st1.high,st1.score);
	printf("%d\t%s\t%.2f\t%.2f\n",st2.sno,st2.name,st2.high,st2.score);
	return 0;
}
