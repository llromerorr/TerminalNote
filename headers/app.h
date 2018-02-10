#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "terminalnote.h"

void app_help(){
    printf("\n%s%-10s %-19s %-20s%s\n", TEXT_BOLD, "COMMAND", "ARGUMNETS", "DESCRIPTION", TEXT_DEFAULT);
    printf("%s%-10s%s %-19s %-20s\n",TEXT_COLOR_FG_LCYAN,"note", TEXT_COLOR_FG_DEFAULT, "{title} | {info}", "create new note in current book");
    printf("%s%-10s%s %-19s %-20s\n",TEXT_COLOR_FG_LWHITE,"show", TEXT_COLOR_FG_DEFAULT, "[all | id]", "show all or specific note by id (default is all)");
    printf("%s%-10s%s %-19s %-20s\n",TEXT_COLOR_FG_LWHITE,"find", TEXT_COLOR_FG_DEFAULT, "{text}", "search for text in the content of any note");
    
    printf("\n%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LYELLOW, "new", TEXT_COLOR_FG_DEFAULT, "{title}", "create a new book");
    printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LYELLOW, "open", TEXT_COLOR_FG_DEFAULT, "[{title} | none]", "open a book, show avalible books");
    printf("%s%-10s%s %-19s %-20s\n",TEXT_COLOR_FG_LRED, "delete", TEXT_COLOR_FG_DEFAULT, "[{title} | id]", "delete book or note");
    
    printf("\n%s%-10s%s %-19s %-20s", TEXT_COLOR_FG_LWHITE, "clear", TEXT_COLOR_FG_DEFAULT, "", "clear screen");
    printf("\n%s%-10s%s %-19s %-20s\n",TEXT_COLOR_FG_LRED, "exit", TEXT_COLOR_FG_DEFAULT, "", "go back to system");
    printf("\n%s%s%s\n\n", TEXT_BOLD, "developed by @CreyTuning 2018 from Venezuela.", TEXT_DEFAULT);
}

void app_errorCommand(){
    printf("can not recognize this command.\n\n");
}

void app_show(){
    printf("there are not notes here, this command will be programmed.\n\n");
}

int app_note(char * input, DB * book){
    char * next = strchr(input, '|');
    if(!next){
        app_errorCommand();
        return -1;
    }
    Note * note = note_null();
    // create a random ID, but this may be unnecessary
    // srand(time(NULL));
    // note->id = (rand() + 1) % 98;
    note->id = book->count + 1;

    next = strchr(input, ' ');
    if(!next){
        app_errorCommand();
        return -1;
    }

    next++;
    sscanf(next, "%500[^|]", note->title);
    note->title[strlen(note->title) - 1] = '\0';

    next = strchr(next, '|') + 1;
    while(next[0] == ' ')
        next++;
    sscanf(next, "%3000[^\n]", note->info);
    note->info[strlen(note->info)] = '\0';

    time_copy(&note->time, time_local());
    date_copy(&note->date, date_local());

    db_add(note, book);
    printf("%s%s+1%s note have been added.%s\n\n", TEXT_BOLD, TEXT_COLOR_FG_GREEN, TEXT_COLOR_FG_DEFAULT,TEXT_DEFAULT);
    return 0;
}

#endif /* APP_H */