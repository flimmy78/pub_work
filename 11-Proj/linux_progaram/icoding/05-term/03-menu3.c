/*******************************************************************
 *   > File Name: 03-menu3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 28 Mar 2017 05:14:11 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *menu[] = {
    "a - add new record",
    "d - delecte record",
    "q - quit",
    NULL,
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main(int argc, char* argv[])
{
    int choice = 0;
    FILE* input;
    FILE *output;

    if(!isatty(fileno(stdout))){
        fprintf(stderr,"You are not a terminal, OK .\n");
    }

    input = fopen("/dev/tty", "r");
    output = fopen("/dev/tty", "w");

    if(!input || !output){
        fprintf(stderr, "Unable to open /dev/tty\n");exit(1);
    }

    do{
        choice = getchoice("Please select an action", menu, input, output);
        printf("You have chosen :%c\n",choice);
    }while(choice != 'q');

    return 0;
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out){
    int chosen = 0;
    int selected;
    char **option;

    do{
        fprintf(out, "Choice :%s\n", greet);
        option = choices;
        while(*option){
            fprintf(out, "%s\n", *option);
            option ++;
        }
        do{
            selected = fgetc(in);
        }while(selected == '\n')
        option = choices;

        while(*option){
            if(selected == *option[0]){
                chosen = 1;
                break;
            }
            option++ ;
        }

        if(!chosen){
            fprintf(out, "Incorrent choice , select again\n");
        }
    }while(!chosen);

        return selected;
}
