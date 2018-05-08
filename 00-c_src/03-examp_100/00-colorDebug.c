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
#define RED             "\033[0;31m" //红色
#define LIGHT_RED       "\033[1;31m"
#define LIGHT_RED1      "\033[1;42;31m"
#define LIGHT_RED2      "\033[1;43;31m"
#define LIGHT_RED3      "\033[1;44;31m"
#define LIGHT_RED4      "\033[1;47;31m"
#define LIGHT_RED5      "\033[7;47;31m"
#define LIGHT_RED6      "\033[5;47;31m"
#define GREEN           "\033[0;32m"
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

typedef enum{
    COLOR_NONE,
    COLOR_RED,
    COLOR_LIGHT_RED,
    COLOR_LIGHT_RED1,
    COLOR_LIGHT_RED2,
    COLOR_LIGHT_RED3,
    COLOR_LIGHT_RED4,
    COLOR_LIGHT_RED5,
    COLOR_LIGHT_RED6,
    COLOR_GREEN,
    COLOR_LIGHT_GREEN,
    COLOR_BLUE,
    COLOR_LIGHT_BLUE,
    COLOR_DARY_GRAY,
    COLOR_GYAN,
    COLOR_LIGHT_CYAN,
    COLOR_PURPLE,
    COLOR_LIGHT_PURPLE,
    COLOR_BROWN,
    COLOR_YELLOW,
    COLOR_LIGHT_GRAY,
    COLOR_WHITE,
    COLOR_MAX
}debug_color;

char *debug_color_str[COLOR_MAX]={
    "\e[m",
    "\e[0;31m",
    "\e[1;31m",
    "\e[1;42;31m",
    "\e[1;43;31m",
    "\e[1;44;31m",
    "\e[1;47;31m",
    "\e[7;47;31m",
    "\e[5;47;31m",
    "\e[0;32m",
    "\e[1;32m",
    "\e[0;34m",
    "\e[1;34;24m",
    "\e[1;30m",
    "\e[0;36m",
    "\e[1;36m",
    "\e[0;35m",
    "\e[1;35m",
    "\e[0;33m",
    "\e[1;33m",
    "\e[0;37m",
    "\e[1;37m",
};

#define     DISABLE  0
#define     ENABLE   1

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

#if (DISABLE)
    puts("Output color_debug:");
    int i;
    for(i = 0; i< COLOR_MAX; i++){
        printf("%s\n", debug_color_str[i]);
    }
#endif

    puts(LIGHT_RED4"This is a test !"NONE);
    
    printf("File :%s, Func :%s, Line :%d\n", __FILE__, __func__, __LINE__);

    return 0;
}
