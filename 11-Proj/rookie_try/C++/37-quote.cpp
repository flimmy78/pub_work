/*******************************************************************
 *   > File Name: 37-quote.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 14:28:53 2017
 ******************************************************************/
//把引用作为参数

#include <iostream>
using namespace std;

//函数声明
void swap(int& x, int& y);

int main(void)
{
    //局部变量声明
    int a = 100;
    int b = 200;

    cout << "交换前，a的值:" << a << endl;
    cout << "交换前，b的值:" << b << endl;

    /*调用函数*/
    swap(a, b);

    cout << "交换后，a的值:" << a << endl;
    cout << "交换后，b的值:" << b << endl;

    return 0;
}

//函数定义
void swap(int& x, int& y){
    int temp;
    temp = x;
    x = y;
    y = temp;

    return;
}
