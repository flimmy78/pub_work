/*******************************************************************
 *   > File Name: 01-static.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2017年07月04日 星期二 21时28分52秒
 ******************************************************************/

#include <stdio.h>

/*函数声明*/
void func1(void);

static int count = 10;  /*全局变量 - static 是默认的*/

int main(int argc, char* argv[])
{
    while(count--){
        func1();
    }
    
    return 0;
}

void func1(void)
{
    /*
     *'thingy'是'func1'的局部变量，-只初始化一次
     *每次调用'func1','thingy'值不会重置
     * */

    static int thingy = 5;
    thingy ++;
    printf("Thingy 为%d, count 为%d\n", thingy, count);
}
