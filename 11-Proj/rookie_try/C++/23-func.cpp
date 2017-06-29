/*******************************************************************
 *   > File Name: 23-func.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 17:15:55 2017
 ******************************************************************/

#include <iostream>
using namespace std;

//函数声明
int max(int num1, int num2);  
int main ()
{
    // 局部变量声明
    int a = 100;
    int b = 200;
    int ret;

    // 调用函数来获取最大值
    ret = max(a, b);

    cout << "Max value is : " << ret << endl;

    return 0;
}

int max(int num1, int num2)
{
    int result;

    if(num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

