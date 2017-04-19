/*******************************************************************
 *   > File Name: menu1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 18 Apr 2017 10:26:57 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>

#define DEBUG   (0)

/*定义一个字符串数组*/
char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};

int getchoice(char *greet, char *choices[]);

int main(int argc, char* argv[])
{
    //initscr();
#if (DEBUG)
    printf("menu-->%p\n", menu);
    printf("menu + 1-->%p\n", menu + 1);
    printf("menu + 2-->%p\n", menu + 2);
    printf("*menu-->%p\n", *menu);

    printf("%s\n",*menu);
    printf("%s\n", *menu + 1);
    printf("%s\n", *menu + 2);
    printf("%s\n", *(menu + 1));
    printf("%s\n", *(menu + 2));
#endif

    int choice = 0;

    do{
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    }while(choice != 'q');
    
    //endwin();
    return 0;
}

int getchoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected ;
    char **option;

    do{
        printf("Choice :%s\n", greet);
        option = choices;

        /*输出字符串数组*/
        while(*option){
            printf("%s\n", *option);
            option ++;
        }
        
        /*输入选项*/
        do{
            selected = getchar();
        }while(selected == '\n');

        option = choices;
        while(*option){
            if(selected == *option[0]){
                chosen = 1;
                break;
            }
            option ++;
        }

        if(!chosen){
            printf("Incorrent choice, select again\n");
        }
    }while(!chosen);
    return selected;
}
