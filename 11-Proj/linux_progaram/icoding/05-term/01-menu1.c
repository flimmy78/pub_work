/*******************************************************************
 *   > File Name: 01-menu1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 07 Apr 2017 03:27:57 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};

int getchoice(char *greet, char *choices[]);

int getchoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected;
    char **option;

    do{
        printf("Choice :%s\n", greet);
        option = choices;
        while(*option){
           printf("%s\n", *option);
           option++;
        }
        selected = getchar();
        option = choices;
        while(*option){
            if(selected == *option[0]){
                chosen = 1;
                break;
            }
            option ++;
        }
        if(!chosen){
            printf("Incorrent choice , select again\n");
        }
    }while(!chosen);
    return selected;
}

int main(int argc, char* argv[])
{
    char **option;
    option = menu;
    while(*option){
        printf("%s\n", *option);
        option ++;
    }

    return 0;
}
