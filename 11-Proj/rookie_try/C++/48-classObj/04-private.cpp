/*******************************************************************
 *   > File Name: 04-private.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 20:33:20 2017
 ******************************************************************/

#include <iostream>
using namespace std;

class Box
{
    public:
        double length;
        void setWidth(double wid);
        double getWidth(void);

    private:
        double width;
};

//成员函数定义
double Box::getWidth(void){
    return width;
}

void Box::setWidth(double wid){
    width = wid;
}

//程序的主函数
int main(void)
{
    Box box;

    //不使用成员函数设置长度
    box.length = 10.0;  //OK:因为length是公有的
    cout << "Length of box : " << box.length << endl;

    //不使用成员函数设置宽度
    //box.width = 10.0; //Error:因为width是私有的
    box.setWidth(10.0); //使用成员函数设置宽度
    cout << "Width of box :" << box.getWidth() << endl;

    return 0;
}
