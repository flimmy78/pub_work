/*******************************************************************
 *   > File Name: 03-circle.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Oct 2017 04:50:57 PM CST
 ******************************************************************/

#include <stdio.h>
#include <math.h>

void Display_circle(unsigned int radius){
    double y;
    int x, m;

    for(y = 10; y >= -10; y--){/*圆的半径为10*/
        /*计算行y对应的列坐标m。2.5是屏幕纵横比调节系数，
         *因为屏幕的行距大于列距，不进行调节显示出来的将是椭圆。
         * */
        m = 2.5 * sqrt(100 - y * y);
        for(x = 1; x < 30 - m; x ++)
            printf(" ");    /*图形左侧空白控制*/
        printf("*");        /*圆的左侧*/
        for(;x < 30 + m; x ++)  /*圆形的空心部分*/
            printf(" ");        /*圆的右侧*/
        printf("*\n");
    }
}

int main(int argc, char* argv[])
{
    Display_circle(0);
    return 0;
}
