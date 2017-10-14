/*******************************************************************
 *   > File Name: 53-Prj_GetBuildDateTime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Oct  9 10:11:57 2017
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("__DATE__:%s\n", __DATE__);
    printf("__TIME__:%s\n", __TIME__);

    return 0;
}
