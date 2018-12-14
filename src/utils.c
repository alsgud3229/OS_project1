#include "utils.h"
#include <string.h>

void mysh_parse_command(const char* command, int* argc, char*** argv) {
    int argnum = 0;
    char* ptr = strtok(command, " \t\n");
    (*argv) = (char**)malloc(sizeof(char*)*1000); 
    
    if(ptr==NULL){
        (*argv)[argnum] = (char*)malloc(sizeof(char));
        strcpy((*argv)[0], "");
    }

    else{
        while (ptr != NULL){
          (*argv)[argnum] = (char*)malloc(sizeof(char));
            strcpy((*argv)[argnum], ptr);
            argnum++;
            ptr = strtok(NULL, " \t\n");
        }
    }
        *argc = argnum;  
}