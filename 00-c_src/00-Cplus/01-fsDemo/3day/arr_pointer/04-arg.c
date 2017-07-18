/*******************************************************************
 *   > File Name: 04-arg.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Jul 15 13:49:56 2017
 ******************************************************************/

#include <stdio.h>

/*说明：
 *argc:表示命令行参数个数
 *argv:表示命令行参数
 * */

int main(int argc, char* argv[])
{
    int i;

    for(i = 0; i< argc; i++){
        printf("argv[%d] :%s\n",i, argv[i]);
    }

    return 0;
}
