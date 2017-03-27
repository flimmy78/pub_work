/*******************************************************************
 *   > File Name: 01-menu1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 16 Mar 2017 01:16:43 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TEST_DEBUG (1)

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL
};

int getchoice(char *greet, char *choices[]);


int main(int argc, char* argv[])
{
    int choice = 0;

    do{
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    }while(choice != 'q');

    return 0;
}

/*  负责显示菜单及读取用户输入的函数getchoice*/
int getchoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected;
    char **option;

    do{
        printf("Choice :%s\n", greet);
        option = choices;
        while(*option){
            printf("%s\n", *option);
            option ++;
        }

#if TEST_DEBUG
        do{
            selected = getchar();
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
        if(!chosen){
            printf("Incorrect choice, select again\n");
        }

    }while(!chosen);
    return selected;
}
