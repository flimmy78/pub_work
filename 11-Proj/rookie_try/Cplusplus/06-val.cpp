/*******************************************************************
 *   > File Name: 06-val.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:00:45 2017
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
    cout <<"123456\n";

    return 0;
}
