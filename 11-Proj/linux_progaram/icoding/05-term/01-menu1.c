/*******************************************************************
 *   > File Name: 01-menu1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 03 May 2017 04:41:36 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define DEBUG
    
/*An array of pointers to string*/
char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};

/*function declaration*/
int getchoice(char *greet, char *choices[]);

int main(int argc, char* argv[])
{
    int choice = 0;

    do{
        choice = getchoice("Please select an action", menu);
        printf("You hava chosen :%c\n", choice);
    }while(choice != 'q');

    return 0;
}

int getchoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected;
    char **option;

    do{
        printf("Choice :%s\n", greet);
        option = choices;
       /*输出菜单*/
        while(*option){
            printf("%s\n", *option);
            option ++;
        }
    
#ifdef DUBUG
        do{
        selected = getchar();/*获得字符输入*/
        }while(selected == '\n');
#else
        selected = getchar();
#endif
        option = choices;
        while(*option){
            if(selected == *option[0]){
                chosen = 1;
                break;
            }
            option ++;
        }
        /*输入错误*/
        if(!chosen){
            printf("Incorrect choice , select again\n");
        }
    }while(!chosen);

    return selected;
}
