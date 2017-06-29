/*******************************************************************
 *   > File Name: 15-static.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:37:11 2017
 ******************************************************************/

#include <iostream>
using namespace std;

//函数声明
void func(void);

static int count = 10;  /*全局变量*/

int main(void)
{
    while(count --){
        func();
    }

    return 0;
}

//函数定义
void func(void){
    static int i = 5;   
    i ++;
    std::cout << "变量i为"<<i;
    std::cout << "、变量count为" << count << std ::endl;
}
