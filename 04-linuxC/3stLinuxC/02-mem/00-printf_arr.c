#include <stdio.h>

void printf_arr_int(int a[], int n);
void printf_arr_ch(char ch[], int n);
void printf_arr_str(char ch[][], int n);

int main(void)
{
	char ch[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	int ch_length = sizeof(ch);
	printf("%d\n",ch_length);
	printf_arr_ch(ch,8);

	return 0;
}

void printf_arr_int(int a[], int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		printf("%d  ",a[i]);
	}
	puts("");
}

void printf_arr_ch(char ch[], int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		printf("%c  ",ch[i]);
	}
	puts("");
}

