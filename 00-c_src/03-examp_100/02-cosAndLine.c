/*******************************************************************
 *   > File Name: 02-cosAndLine.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Oct 2017 03:45:28 PM CST
 ******************************************************************/

#include <stdio.h>
#include <math.h>

#define GREEN   "\e[0;32;32m"
#define PURPLE  "\e[0;35m"
#define NONE    "\e[m"

void Display_cosAndLine(void){
    double y;
    int x, m, n, yy;

    for(yy = 0; yy <= 20; yy ++){
        y = 0.1 * yy;           /*对于每一个y坐标进行计算并在一行中打印图形*/
        m = acos(1 - y) * 10;   /*y：屏幕行方向坐标*/
        n = 45 * (y - 1) + 31;  /*m:cos(x)曲线上y点对应的屏幕裂坐标*/
        for(x = 0; x <= 62 ; x++)   /*n：直线上y点对应的屏幕列坐标*/
            if(x == m && x == n)    /*x：屏幕列方向坐标*/
                printf(PURPLE"+"NONE);        
            else if (x == n)        /*直线与cos(x)相交时打‘+’*/
                printf(PURPLE"+"NONE);
            else if (x == m || x == 62 -m)  /*打印不相交时的直线图形*/
                printf(GREEN"*"NONE);
            else                        
                printf(" ");    /*其他情况打印空格*/
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    Display_cosAndLine();
    return 0;
}
