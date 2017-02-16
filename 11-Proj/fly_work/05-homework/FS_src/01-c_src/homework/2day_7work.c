#include <stdio.h>
int main(void)
{
	char ch;
	int i,line,j,k;

	scanf("%c",&ch);
	line = ch - 'A' + 1;

	for(i = 0; i < line; i++){
		for(j = 0; j < line - i - 1; j++)
			printf("%c",' ');
		for(k = 0;k <= i; k++)
			printf("%c",'A' + k);
		for(--k;k > 0; k--)
			printf("%c",'A' + k -1);
		printf("\n");
	}

	return 0;
}
