/*******************************************************************
 *   > File Name: 13-check_char.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 03 Jan 2017 02:41:05 PM CST
 ******************************************************************/

#include <stdio.h>

int check_char(char byte);

int main(void)
{
    char ch;
    printf("Please input a char : ");
    scanf("%c",&ch);
    printf("ret = %d\n",check_char(ch));
    return 0;
}

int check_char(char byte)
{
    int i = 0,num = 0;

    do{
        if(byte&(1<<i))
            num ++;
    }while(i++ <8);
    return num;
}
