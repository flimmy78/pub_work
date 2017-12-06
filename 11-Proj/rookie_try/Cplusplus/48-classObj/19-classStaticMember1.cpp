/*******************************************************************
 *   > File Name: 19-classStaticMember1.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Dec  6 18:08:10 2017
 ******************************************************************/


#include <iostream>
 
#define TEST_KEY    0
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

#if (TEST_KEY)
// 初始化类 Box 的静态成员   其实是定义并初始化的过程
int Box::objectCount = 0;
#else
//也可这样 定义却不初始化
int Box::objectCount;
#endif
int main(void)
{
    Box Box1(3.3, 1.2, 1.5);    // 声明 box1
    Box Box2(8.5, 6.0, 2.0);    // 声明 box2

    // 输出对象的总数
    cout << "Total objects: " << Box::objectCount << endl;

    return 0;
}
