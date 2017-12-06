/*******************************************************************
 *   > File Name: 08-globalVal.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:08:05 2017
 ******************************************************************/

#include <iostream>
using namespace std;

//全局变量声明
int g;

int main(void)
{
    //局部变量声明
    int a,b;

    //实际初始化
    a = 10;
    b = 20;
    g = a + b;

    cout << g << endl;

    return 0;
}
