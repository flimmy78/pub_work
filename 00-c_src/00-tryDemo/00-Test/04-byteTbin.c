/*******************************************************************
 *   > File Name: 04-byteTbin.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 04 Jan 2017 09:32:57 AM CST
 ******************************************************************/

#include <stdio.h>

void byteTobin(unsigned char value);
void printf_IntArr(int a[], int n);

int main(void)
{
    while(1)
    {
        char CH;
        printf("Pls input a integer(0 ~ 255):");
        scanf("%d",&CH);
        byteTobin(CH);
    }
    return 0;
}

void byteTobin(unsigned char value)     //with a bug ,waiting debug
{
    int a[8];   //定义一个整型数组，用于存储bit
    int i;
    
    for(i = 0; i < 8; i++)
    {
        a[i] = value &(0x01 << i);
    }
    printf_IntArr(a,8);

}

void printf_IntArr(int a[], int n)
{
    int i;
    for(i = 7; i >= 0; i--)
        printf("%d",a[i]);
    printf("\n");
}
