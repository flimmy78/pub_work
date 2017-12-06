/*******************************************************************
 *   > File Name: 09-globalVal.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:10:26 2017
 ******************************************************************/

#include <iostream>
using namespace std;

//全局变量声明
int g = 20;

int main(void)
{
    //局部变量声明
    int g = 10;

    cout << g << endl;

    return 0;
}
