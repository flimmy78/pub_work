#include <stdio.h>

struct student{
	int sno;
	char name[20];
	float high;
	float score;
};

int main(void)
{
	struct student st1 = {1001,"刘德华",1.80,99.9};  //完全初始化
	struct student st2 = {1001,"刘德华",1.80};  //部分初始化
	struct student st3 = {.name="刘德华",1.80,.sno=1001};  //指定成员初始化
	

	printf("sizeof(struct student) = %d\n",sizeof(struct student));
	printf("sizeof(st) = %d\n",sizeof(st));
	return 0;
}
