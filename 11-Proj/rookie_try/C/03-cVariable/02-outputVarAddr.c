/*******************************************************************
 *   > File Name: 02-outputVarAddr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年07月04日 星期二 21时08分15秒
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a;
    int b;

    printf("a的地址是%p\nb的地址是%p\n", &a, &b);

    return 0;
}
