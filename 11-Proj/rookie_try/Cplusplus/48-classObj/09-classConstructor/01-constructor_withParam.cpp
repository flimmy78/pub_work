/*******************************************************************
 *   > File Name: 01-constructor_withParam.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Nov 25 17:29:22 2017
 ******************************************************************/
#include <iostream>

using namespace std;

class Line
{
    public:
        void setLength( double len );
        double getLength( void );
        Line(double len);  // 这是构造函数

    private:
        double length;
};

// 成员函数定义，包括构造函数
Line::Line( double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

void Line::setLength( double len )
{
    length = len;
}

double Line::getLength( void )
{
    return length;
}
// 程序的主函数
int main( )
{
    Line line(10.0);//构造函数也可以带有参数。这样在创建对象时就会给对象赋初始值

    // 获取默认设置的长度
    cout << "Length of line : " << line.getLength() <<endl;
    // 再次设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;

    return 0;
}

