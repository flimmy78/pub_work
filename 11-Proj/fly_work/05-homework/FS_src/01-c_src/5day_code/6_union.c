#include <stdio.h>
#include <string.h>

union student{
	int sno;
	char name[20];
	float high;
	float score;
};

int main(void)
{
	union student un1; 
	
	un1.sno = 1001;
	strcpy(un1.name,"jack");
	un1.high = 1.80;
	un1.score = 93.5;
	printf("%d\t%s\t%f\t%f\n",un1.sno,un1.name,un1.high,un1.score);
	printf("************************\n");
	un1.sno = 1001;
	strcpy(un1.name,"jack");
	un1.score = 93.5;
	un1.high = 1.80;
	printf("%d\t%s\t%f\t%f\n",un1.sno,un1.name,un1.high,un1.score);
	printf("************************\n");
	un1.sno = 1001;
	un1.high = 1.80;
	un1.score = 93.5;
	strcpy(un1.name,"jack");
	printf("%d\t%s\t%f\t%f\n",un1.sno,un1.name,un1.high,un1.score);
	printf("************************\n");
	strcpy(un1.name,"jack");
	un1.high = 1.80;
	un1.score = 93.5;
	un1.sno = 1001;
	printf("%d\t%s\t%f\t%f\n",un1.sno,un1.name,un1.high,un1.score);

	printf("&un1 = %p\n",&un1);
	printf("&un1+1 = %p\n",&un1+1);
	printf("&un1.sno = %p\n",&un1.sno);
	printf("&un1.sno + 1= %p\n",&un1.sno+1);
	printf("&un1.name = %p\n",&un1.name);
	printf("&un1.name + 1= %p\n",&un1.name+1);
	printf("&un1.high = %p\n",&un1.high);
	printf("&un1.high + 1= %p\n",&un1.high+1);
	printf("&un1.score  = %p\n",&un1.score);
	printf("&un1.score + 1 = %p\n",&un1.score+1);
	return 0;
}
