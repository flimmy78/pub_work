/*******************************************************************
 *   > File Name: 05-val.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 15 May 2017 03:28:59 PM CST
 ******************************************************************/

#include <iostream>
using namespace std;

//变量声明
extern int a,b;
extern int c;
extern float f;

int main(void)
{
    //变量定义
    int a,b;
    int c;
    float f;

    //实际初始化
    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl;

    f = 70.0/3.0;
    cout << f << endl;

    return 0;
}
