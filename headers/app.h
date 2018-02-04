#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <crypt.h>
#include "terminalnote.h"

int app_openBook(){
    printf("%s", "Book: myNewBook\n");
    char * pass = getpass("your pass: ");
    puts(pass);
    return 0;
}

void app_help(){
    printf("\n%-10s %-20s %-20s\n","COMMAND", "ARGUMNETS", "DESCRIPTION");
    printf("%-10s %-20s %-20s\n","note", "{title} | {info}", "create new note in current book");
    printf("%-10s %-20s %-20s\n","show", "[all | id]", "show all or specific note by id (default is all)");
    printf("%-10s %-20s %-20s\n","find", "{text}", "search for text in the content of any note");
    
    printf("\n%-10s %-20s %-20s\n","new", "{title}", "create a new book");
    printf("%-10s %-20s %-20s\n","open", "[{title} | none]", "open a book, show avalible books");
    printf("%-10s %-20s %-20s\n","delete", "[{title} | id]", "delete book or note");
    
    printf("\n%-10s %-20s %-20s\n","exit", "", "go back to system");
    printf("\n%s", "developed by @CreyTuning 2018 from Venezuela.\n\n");
}

void app_errorCommand(){
    printf("can not recognize this command.\n\n");
}

void app_show(){
    printf("there are not notes here, this command will be programmed.\n\n");
}

#endif /* APP_H */