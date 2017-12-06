/*******************************************************************
 *   > File Name: 17-classStaticMember.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Dec  6 17:43:54 2017
 ******************************************************************/

/*@Note:
 * 我们可以使用 static 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
 *
 * 静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
 *
 * */
#include <iostream>

using namespace std;

class Box
{
    public:
        static int objectCount;
        // 构造函数定义
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout <<"Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
            // 每次创建对象时增加 1
            objectCount++;
        }
        double Volume()
        {
            return length * breadth * height;
        }
    private:
        double length;     // 长度
        double breadth;    // 宽度
        double height;     // 高度
};

// 初始化类 Box 的静态成员
int Box::objectCount = 0;

int main(void)
{
    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    // 输出对象的总数
    cout << "Total objects: " << Box::objectCount << endl;

    return 0;
}
