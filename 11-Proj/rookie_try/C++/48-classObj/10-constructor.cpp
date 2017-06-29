/*******************************************************************
 *   > File Name: 10-constructor.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 22 17:16:32 2017
 ******************************************************************/

#include <iostream>
using namespace std;

class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line(double len);   //构造函数

    private:
        double length;
};

//成员函数定义，包括构造函数
Line::Line(double len)
{
    cout << "Object is being created , length = "<< len << endl;
    length = len;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

//程序的主函数
int main(void)
{
    Line line(10.0);

    //获取默认设置的长度
    cout << "Length of line :" << line.getLength() << endl;
    //再次设置长度
    line.setLength(6.0);
    cout << "Length of line :"<< line.getLength() << endl;

    return 0;
}
