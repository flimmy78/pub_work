/*******************************************************************
 *   > File Name: 00-constructor.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Nov 25 17:21:54 2017
 ******************************************************************/

#include <iostream>
using namespace std;

class Line{
    public:
        void setLength(double len);
        double getLength(void);
        Line();//构造函数

    private:
        double length;
};

//成员函数定义，包括构造函数
Line::Line(void){
    cout<<"Object is being created"<<endl;
}

void Line::setLength( double len )
{
    length = len;
}

double Line::getLength( void )
{
    return length;
}

int main(void)
{
    Line line;

    // 设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;
    return 0;
}
