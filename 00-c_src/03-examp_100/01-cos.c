/*******************************************************************
 *   > File Name: 01-cos.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Oct 2017 01:13:41 PM CST
 ******************************************************************/

#include <stdio.h>
#include <math.h>

#define LIGHT_WHITE_GREEN   "\e[1;47;32m"
#define PURPLE              "\e[0;35m"
#define NONE                "\e[m"

/*在屏幕上显示0~360度的余弦函数cos（x）的曲线
 * */
void Display_cos(void){
    double y;
    int x, m;

    for(y = 1; y >= -1; y -= 0.1){  //y为列方向，值从-1到1，步长为0.1
        m = acos(y) * 10;       //计算出y对应的弧度m，乘10为图形放大倍数
        for(x = 1; x < m; x++){ 
            printf(PURPLE"+"NONE);
        }
        printf(LIGHT_WHITE_GREEN"*"NONE);//printf("(%2d,%2d)", x, m);//控制左侧打印的“*”号
        for(; x < 62 - m; x++){
            printf("-");
        }
        printf(LIGHT_WHITE_GREEN"*"NONE);//printf("(%2d,%2d)", x, m);//控制右侧打印的“*”号
        for(x = 1; x <= m; x++){
            printf(PURPLE"+"NONE);
        }
        puts("");
    }
}

int main(int argc, char* argv[])
{
    Display_cos();

    return 0;
}
