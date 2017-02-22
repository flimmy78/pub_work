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
	struct student st[5];
	int i;
	for(i = 0; i < 5; i++)
		scanf("%d%s%f%f",&st[i].sno,st[i].name,&st[i].high,&st[i].score);
	for(i = 0; i < 5; i++)
		printf("%d\t%s\t%.2f\t%.2f\n",st[i].sno,st[i].name,st[i].high,st[i].score);

	return 0;
}
