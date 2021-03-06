/*******************************************************************
 *   > File Name: 05-protected.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 20:49:18 2017
 ******************************************************************/
/*NOTE
 * 保护成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的。
 * */

#include <iostream>
using namespace std;

class Box
{
    protected:// 受保护成员
        double width;
};

class SmallBox:Box  //SmallBox是派生类
{
    public:
        void setSmallWidth(double wid);
        double getSmallWidth(void);
};

//子类的成员函数
double SmallBox::getSmallWidth(void)
{
    return width;
}

void SmallBox::setSmallWidth(double wid)
{
    width = wid;
}

//程序的主函数
int main(void)
{
    SmallBox box;

    //使用成员函数设置宽度
    box.setSmallWidth(5.0);
    cout << "Width of box :" << box.getSmallWidth() << endl;

    return 0;
}
