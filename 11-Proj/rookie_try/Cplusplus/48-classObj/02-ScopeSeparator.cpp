/*******************************************************************
 *   > File Name: 02-ScopeSeparator.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Nov 25 16:45:41 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    return 0;
}

int month;//全局变量
int day;
int year;
void Set(int m,int d,int y)
{
    ::year=y; //给全局变量赋值，此处可省略
    ::day=d;
    ::month=m;
}

class Tdate
{
    public:
        void Set(int m,int d,int y) //成员函数
        {
            ::Set(m,d,y); //非成员函数
        }
    private:
        int month;
        int day;
        int year;
}
