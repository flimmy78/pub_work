/*******************************************************************
 *   > File Name: PredefineMacros.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 12:41:20 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __func__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%d\n", __STDC__);

    return 0;
}
