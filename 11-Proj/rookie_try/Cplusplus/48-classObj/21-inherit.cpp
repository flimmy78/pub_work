/*******************************************************************
 *   > File Name: 21-inherit.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Dec  6 19:42:04 2017
 ******************************************************************/

#include <iostream>
using namespace std;

#define TEST_KEY 1

//基类
class Shape{
    public:
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }
#if (TEST_KEY)
    protected:
#else
    private:
#endif
        int width;
        int height;
};

//派生类
class Rectangle: public Shape{
    public:
        int getArea(){
            return (width * height);
        }
};

int main(void)
{
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    //输出对象的面积
    cout << "Total area :" << Rect.getArea() << endl;

    return 0;
}
