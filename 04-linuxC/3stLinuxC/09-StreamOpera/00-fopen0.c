#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//#define FILEPATH "/home/fly/pub_work/04-linuxC/3stLinuxC/09-StreamOpera/mytestfile/test.txt"

//char SEX[2][2] = {"男","女"};

struct people
{
	char name[10];
	bool sex;
	int age;
};

int main(int argc, char **argv)
{
	FILE *fp;
	int ret;

	if(argc != 2)
	{
		printf("Usage : %s filepath\n",argv[0]);
		exit(1);
	}
	else
	{
		fp = fopen(argv[1],"r+");
		if(fp == NULL)
		{
			perror("fopen file err");
			return -1;
		}
	}

	struct people sun;
#if (0)
	fscanf(stdin,"%s%d%d",sun.name,(int *)&sun.sex,&sun.age);
#else
	fscanf(fp,"%s%d%d",sun.name,(int *)&sun.sex,&sun.age);
#endif
	//sun.sex = (sun.sex != 0) ? true : false;

	printf("Name : %s\nSex : %d\nAge : %d\n",sun.name,sun.sex,sun.age);

	fclose(fp);

	return 0;
}
