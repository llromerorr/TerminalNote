#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "terminalnote.h"

void app_help(){
    printf("\n%-10s %-19s %-20s\n","COMMAND", "ARGUMNETS", "DESCRIPTION");
    printf("%-10s %-19s %-20s\n","note", "{title} | {info}", "create new note in current book");
    printf("%-10s %-19s %-20s\n","show", "[all | id]", "show all or specific note by id (default is all)");
    printf("%-10s %-19s %-20s\n","find", "{text}", "search for text in the content of any note");
    
    printf("\n%-10s %-19s %-20s\n","new", "{title}", "create a new book");
    printf("%-10s %-19s %-20s\n","open", "[{title} | none]", "open a book, show avalible books");
    printf("%-10s %-19s %-20s\n","delete", "[{title} | id]", "delete book or note");
    
    printf("\n%-10s %-19s %-20s\n","exit", "", "go back to system");
    printf("\n%s", "developed by @CreyTuning 2018 from Venezuela.\n\n");
}

void app_errorCommand(){
    printf("can not recognize this command.\n\n");
}

void app_show(){
    printf("there are not notes here, this command will be programmed.\n\n");
}

void app_init(){
    char * input = malloc(sizeof(char) * 1000);
    
    DB * book = db_open("myBook");
    if(book == NULL)
        book = db_new("myBook", sizeof(Note));
    
    char * user = getenv("USER");
    if(user == NULL)
        user = "none";

    printf("TerminalNote %s [%s]\n", _APPLICATION_VERSION_, time_GetLocalTime());
    printf("if you need help type \"help\"\n\n");
    while(true){
        printf("%s[%s]: ", user, book->name);
        fgets(input, 100, stdin);
        
        if(strstr(input, "help") != NULL)
            app_help();
        else if(strcmp(input, "show\n")==0)
            db_show(book);
        else if(strcmp(input, "exit\n")==0)
            exit(-1);
        else 
            app_errorCommand();
    }
}

#endif /* APP_H */