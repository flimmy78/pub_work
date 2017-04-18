/*******************************************************************
 *   > File Name: menu1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 18 Apr 2017 10:26:57 AM CST
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

int main(int argc, char* argv[])
{
    int choice = 0;
    
    do{
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    }while(choice != 'q');

    return 0;
}

int getchoice(char *greet, char *choices[]){
    int chosen = 0;
    int selected ;
    char **option;

    do{
        printf("Choice :%s\n", greet);
        option = choices;
        while(*option){
            printf("%s\n", *option);
            option ++;
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
            printf("Incorrent choice, select again\n");
        }
    }while(!chosen);
    return selected;
}
