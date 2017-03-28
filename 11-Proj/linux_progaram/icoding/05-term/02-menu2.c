/*******************************************************************
 *   > File Name: 02-menu2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Mar 2017 01:55:24 PM CST
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};

int getchoice(char *greet, char *choices[]);

int main(int argc, char* argv[])
{
    int choice = 0;

    if(!isatty(fileno(stdout))){
        fprintf(stderr,"You are not a terminal\n");
        exit(1);
    }

    do{
        choice = getchoice("Please select an action",menu);
        printf("You have chosen:%c\n",choice);
    }while(choice != 'q');


    return 0;
}

int getchoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected;
    char **option;

    do{
        printf("Choice :%s\n",greet);
        option = choices;

        /*打印菜单*/
        while(*option){
            printf("%s\n", *option);
            option++;
        }

        do{
            selected = getchar();/* 获取一个字符 */
        }while(selected == '\n');
        option = choices;

        while(*option){
            if(selected == *option[0]){ /*输入的字符与菜单选项相符*/
                chosen = 1;
                break;
            }
            option ++;
        }
        if(!chosen){
            printf("Incorect choice, select again\n");
        }

    }while(!chosen);

    return selected;
}
