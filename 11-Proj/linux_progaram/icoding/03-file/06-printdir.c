/*******************************************************************
 *   > File Name: 06-printdir.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun  7 14:33:02 2017
 ******************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    /*open a directory*/
    if((dp = opendir(dir)) == NULL){
        fprintf(stderr, "Cannot open directory :%s\n", dir);
        return;
    }

    /*change working directory*/
    chdir(dir);
    while((entry = readdir(dp)) != NULL){
        lstat(entry -> d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            /* Found a directory ,but ignore .add ... */
            if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry -> d_name) == 0 )
                continue;
            printf("%*s%s/\n", depth, "", entry->d_name);
            /* Recurse at a new indent level */
            printdir(entry->d_name, depth + 4);
        }else{
            printf("%*s%s\n",depth, "",entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}

int main(int argc, char* argv[])
{
    /*
    if(argc < 2 && argc > 2){
        printf("Usage : %s <DIR_pathname>\n", argv[0]);
    }else if()*/
    

    printf("Directory scan of /home :\n");
    printdir("../", 0);
    printf("done.\n");

    exit(1);
}
