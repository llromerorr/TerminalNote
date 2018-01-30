#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "terminalnote.h"

void app_help(){
    printf("\n%-10s %-20s %-20s\n","COMMAND", "ARGUMNETS", "DESCRIPTION");
    printf("%-10s %-20s %-20s\n","note", "{title} | {info}", "create new note");
    printf("%-10s %-20s %-20s\n","show", "[all | id]", "show all or specific note by id (default is all)");
    printf("%-10s %-20s %-20s\n","find", "{text}", "search for text in the content of any note");
    printf("%-10s %-20s %-20s\n","exit", "", "go back to system");
    putchar('\n');
}

void app_errorCommand(){
    printf("can not recognize this command.\n\n");
}

void app_show(){
    printf("there are not notes here, this command will be programmed.\n\n");
}

int app_getCommand(){
    char * input = malloc(sizeof(char) * 100);
    printf("TerminalNote %s [%s]\n", _APPLICATION_VERSION_, time_GetLocalTime());
    printf("if you need help type \"help\"\n\n");
    while(true){
        printf(">> ");
        fgets(input, 100, stdin);
        
        if(strcmp(input, "help\n")==0)
            app_help();
        else if(strcmp(input, "show\n")==0)
            app_show();
        else if(strcmp(input, "exit\n")==0)
            exit(-1);
        else 
            app_errorCommand();
    }
    return EXIT_SUCCESS;
}

#endif /* APP_H */