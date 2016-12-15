#include <stdio.h>

int main(void)
{
	int h;
	int *pH;
	int **ppH;
	int ***pppH;

	h = 100;
	pH = &h;
	ppH = &pH;
	pppH = &ppH;

	printf("h = %d \n",h);

	printf("pH = %p \n",pH);
	printf("*pH = %d \n\n",*pH);

	printf("ppH = %p \n",ppH);
	printf("*ppH = %p \n",*ppH);
	printf("**ppH = %d \n\n",**ppH);

	printf("pppH = %p \n",pppH);
	printf("*pppH = %p \n",*pppH);
	printf("**pppH = %p \n",**pppH);
	printf("***pppH = %d \n\n",***pppH);

	return 0;
}
