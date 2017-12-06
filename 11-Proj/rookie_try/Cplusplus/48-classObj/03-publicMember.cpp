/*******************************************************************
 *   > File Name: 03-public.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 20:16:40 2017
 ******************************************************************/
/*NOTE
 * 在类里面不写是什么类型，默认是 private 的。
 * */

#include <iostream>
using namespace std;

class Line
{
    public:// 公有成员
        double length;
        void setLength(double len);
        double getLength(void);
};

//成员函数定义
double Line::getLength(void){
    return length;
}

void Line::setLength(double len){
    length = len;
}

//程序的主函数
int main(void)
{
    Line line;

    //设置长度
    line.setLength(6.0);
    cout << "Length of line :" << line.getLength() << endl;

    //不使用成员函数设置长度
    line.length = 10.0; //OK:因为length是公有的
    cout << "Length of line : " << line.length << endl;

    return 0;
}
