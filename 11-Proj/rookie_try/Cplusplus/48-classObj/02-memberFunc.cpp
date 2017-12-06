/*******************************************************************
 *   > File Name: 02-memberFunc.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 19:45:11 2017
 ******************************************************************/

/*NOTE
 * :: 叫作用域区分符，指明一个函数属于哪个类或一个数据属于哪个类。
 *:: 可以不跟类名，表示全局数据或全局函数（即非成员函数）。
 *
 * */

#include <iostream>
using namespace std;

class Box
{
    public:
        double length;  //长度
        double breadth; //宽度
        double height;  //高度

        //成员函数声明
        double getVolume(void);
        void setLenght(double len);
        void setBreadth(double bre);
        void setHeight(double hei);
};

//成员函数
//在类的外部使用范围解析运算符 :: 定义该函数
double Box::getVolume(void){
    return length * breadth * height;
}

void Box::setLenght(double len){
    length = len;
}

void Box::setBreadth(double bre){
    breadth = bre;
}

void Box::setHeight(double hei){
    height = hei;
}

//程序的主函数
int main(void)
{
    Box Box1;   //声明Box1，类型为Box(创建一个对象)
    Box Box2;   //声明Box2，类型为Box
    double volume = 0.0;    //用于存储体积

    //Box1 详述
    Box1.setLenght(6.0);//调用该对象的成员函数
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    //Box2 详述
    Box2.setLenght(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    //Box1 的体积
    volume = Box1.getVolume();
    cout << "Box1 的体积 :" << volume << endl;

    //Box2 的体积
    volume = Box2.getVolume();
    cout << "Box2 的体积 :" << volume << endl;

    return 0;
}
