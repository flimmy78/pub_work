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
	struct student *ps;   //ps为结构体指针

	ps = &st1;

	printf("%d\t%s\t%.2f\t%.2f\n",st1.sno,st1.name,st1.high,st1.score);
	printf("%d\t%s\t%.2f\t%.2f\n",(*ps).sno,(*ps).name,(*ps).high,(*ps).score);
	printf("%d\t%s\t%.2f\t%.2f\n",ps->sno,ps->name,ps->high,ps->score);
	return 0;
}
