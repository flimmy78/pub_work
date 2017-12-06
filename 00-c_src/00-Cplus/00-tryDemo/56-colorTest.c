/*******************************************************************
 *   > File Name: 56-colorTest.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Oct 19 19:54:11 2017
 ******************************************************************/

#include <stdio.h>

#define GREEN   "\e[0;32m"
#define RED     "\e[0;31m"
#define BLUE    "\e[0;34m"
#define NONE    "\e[m"

int main(int argc, char* argv[])
{
    printf("FILE = "BLUE __FILE__ NONE", FUNC = "GREEN"%s"NONE", LINE = "RED"%d"NONE"\n", __FUNCTION__, __LINE__);

    return 0;
}
