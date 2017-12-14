/*******************************************************************
 *   > File Name: 00-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 15 Oct 2017 11:46:46 AM CST
 ******************************************************************/

#include <stdio.h>

/*-----------------------------------color------------------------
 *Format:\033[attribute;backgroudColor;fontColor
 * 30~39: set the color of font; 40~49:set the color of backgroud;
 * 0:close all attributes;
 * 1:set the attributes:light and wide font;
 * 4:line
 * 5:flicker
 * 7:reverse display
 * 8:blanking
 * */
#define NONE            "\033[m"        //复原
#define RED             "\033[0;32;31m" //红色
#define LIGHT_RED       "\033[1;31m"
#define LIGHT_RED1      "\033[1;42;31m"
#define LIGHT_RED2      "\033[1;43;31m"
#define LIGHT_RED3      "\033[1;44;31m"
#define LIGHT_RED4      "\033[1;47;31m"
#define LIGHT_RED5      "\033[7;47;31m"
#define LIGHT_RED6      "\033[5;47;31m"
#define GREEN           "\033[0;32;32m"
#define LIGHT_GREEN     "\e[1;32m"
#define BLUE            "\033[0;34m"
#define LIGHT_BLUE      "\033[1;34;24m"
#define DARY_GRAY       "\033[1;30m"    //深灰
#define GYAN            "\033[0;36m"    //蓝绿色
#define LIGHT_CYAN      "\033[1;36m"
#define PURPLE          "\033[0;35m"
#define LIGHT_PURPLE    "\033[1;35m"
#define BROWN           "\033[0;33m"
#define YELLOW          "\033[1;33m"
#define LIGHT_GRAY      "\033[0;37m"    //高亮灰
#define WHITE           "\033[1;37m"    //白色

int main(int argc, char* argv[])
{
    puts(RED"RED"NONE);
    puts(LIGHT_RED"LIGHT_RED"NONE);
    puts(LIGHT_RED1"LIGHT_RED1"NONE);
    puts(LIGHT_RED2"LIGHT_RED2"NONE);
    puts(LIGHT_RED3"LIGHT_RED3"NONE);
    puts(LIGHT_RED4"LIGHT_RED4"NONE);
    puts(LIGHT_RED5"LIGHT_RED5"NONE);
    puts(LIGHT_RED6"LIGHT_RED6"NONE);
    puts(GREEN"GREEN"NONE);
    puts(LIGHT_GREEN"LIGHT_GREEN"NONE);
    puts(BLUE"BLUE"NONE);
    puts(LIGHT_BLUE"LIGHT_BLUE"NONE);
    puts(DARY_GRAY"DARY_GRAY"NONE);
    puts(GYAN"GYAN"NONE);
    puts(LIGHT_CYAN"LIGHT_CYAN"NONE);
    puts(PURPLE"PURPLE"NONE);
    puts(LIGHT_PURPLE"LIGHT_PURPLE"NONE);
    puts(BROWN"BROWN"NONE);
    puts(YELLOW"YELLOW"NONE);
    puts(LIGHT_GRAY"LIGHT_GRAY"NONE);
    puts(WHITE"WHITE"NONE);

    puts(LIGHT_RED4"This is a test !"NONE);
    
    return 0;
}