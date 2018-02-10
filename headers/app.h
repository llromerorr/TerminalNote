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

void app_noteError(){
    printf("%sSyntax error in note command%s\n\n", TEXT_COLOR_FG_LRED, TEXT_DEFAULT);
    printf("%s%-10s %-19s %-20s%s\n", TEXT_BOLD, "COMMAND", "ARGUMNETS", "DESCRIPTION", TEXT_DEFAULT);
    printf("%s%-10s%s %-19s %-20s\n",TEXT_COLOR_FG_LCYAN,"note", TEXT_COLOR_FG_DEFAULT, "{title} | {info}", "create new note in current book");
    printf("%53s\"%shelp%s\"\n\n", "if you need help type ", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
}

void app_show(){
    printf("there are not notes here, this command will be programmed.\n\n");
}

int app_note(char * input, DB * book){
    char * next = strchr(input, '|');
    if(!next){
        app_noteError();
        return -1;
    }
    Note * note = note_null();
    note->id = book->count + 1;

    //search first chart to title
    for(int i = 0;; i++)
        if(input[i] != ' '){
            next = &input[i];
            break;
        }

    next = strchr(next, ' ');
    if(!next){
        app_noteError();
        return -1;
    }

    //delete spaces before title
    for(int i = 0;; i++){
        if(next[i] == '\0'){
            app_noteError();
            return -1;
        }

        else if(next[i] == '|')
            break;

        else if(next[i] != ' '){
            next = &next[i];
            sscanf(next, "%500[^|]", note->title);
            break;
        }
    }

    //delete ending spaces to title
    for (int i = strlen(note->title) - 1;; i--){
        if(note->title[i] != ' '){
            note->title[i + 1] = '\0';
            break;
        }
    }

    //search first character of info
    next = strchr(next, '|') + 1;
    while(next[0] == ' ')
        next++;
    sscanf(next, "%3000[^\n]", note->info);
    
    //delete ending spaces to title
    for (int i = strlen(note->info) - 1;; i--){
        if(note->info[i] != ' '){
            note->info[i + 1] = '\0';
            break;
        }
    }

    time_copy(&note->time, time_local());
    date_copy(&note->date, date_local());

    db_add(note, book);
    printf("\n%s%s+1%s note have been added.%s\n", TEXT_BOLD, TEXT_COLOR_FG_GREEN, TEXT_COLOR_FG_DEFAULT,
                                                   TEXT_DEFAULT);
    printf("    %s -> %s %ssuccessful%s\n",console_stringCuted(note->title, 10), book->name, TEXT_COLOR_FG_LGREEN,
                                        TEXT_DEFAULT);
    printf("    %s%d%s notes, total size %s%.3fMB%s\n\n",
                                                TEXT_COLOR_FG_LYELLOW, book->count,
                                                TEXT_COLOR_FG_DEFAULT, TEXT_COLOR_FG_LYELLOW,
                                                book->count * 0.003515625, TEXT_COLOR_FG_DEFAULT);
    return 0;
}

#endif /* APP_H */