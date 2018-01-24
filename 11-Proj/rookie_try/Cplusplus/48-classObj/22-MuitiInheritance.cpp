/*******************************************************************
 *   > File Name: 22-MuitiInheritance.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Dec  7 11:48:14 2017
 ******************************************************************/

#include <iostream>
using namespace std;

//基类Shape
class Shape{
    public:
        void setWidth(int w){
            width = w;
        }
        void setLength(int h){
            length = h;
        }
    protected:
        int width;
        int length;
};

//基类PaintCost
class PaintCost{
    public:
        int getCost(int area){
            return area * 70;
        }
};

//派生类
class Rectangle:public Shape, public PaintCost{
    public:
        int getArea(){
            return (width * length);
        }
};

int main(void)
{
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setLength(7);

    area = Rect.getArea();

    //输出对象的面积
    cout << "Total area :" << Rect.getArea() << endl;

    //输出总花费
    cout << "Total paint cost :$" << Rect.getCost(area) << endl;

    return 0;
}
