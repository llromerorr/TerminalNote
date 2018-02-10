#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include "textformat.h"

typedef struct{
    FILE *  file;
    char *  name;
    size_t  size;
    int     count;
}DB;

DB * db_new(char * name, size_t size){
    DB * database = malloc(sizeof(DB));
    if((database) == NULL || (database->file = fopen(name, "wb")) == NULL)
        return NULL;
    
    database->size = size;
    database->name = name;
    database->count = 0;
    fwrite(database, sizeof(DB), 1, database->file);
    fclose(database->file);
    return database;
}

DB * db_open(char * name){
    DB * database = malloc(sizeof(DB));
    FILE * file = fopen(name, "rb");
    if(file == NULL){
        return NULL;
    }

    fseek(file, 0, SEEK_SET);
    fread(database, sizeof(DB), 1, file);
    database->file = file;
    fclose(file);
    return database;
}

int db_add(void * obj, DB * database){
    if((database->file = fopen(database->name, "ab")) == NULL){
        printf("%s \"%s\"\n", "can't open file", database->name);
        return EXIT_FAILURE;
    }
    fwrite(obj, database->size, 1 , database->file);
    fclose(database->file);

    database->count++;
    if((database->file = fopen(database->name, "r+b")) == NULL){
        printf("%s \"%s\"\n", "can't open file", database->name);
        return EXIT_FAILURE;
    }
    fseek(database->file, 0, SEEK_SET);
    fwrite(database, sizeof(DB), 1, database->file);
    fclose(database->file);
    return 0;
}

int db_show(DB * database){
    if(database->count == 0){
        printf("this book is empty (use '%snote%s' to add new notes).\n\n", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
        return 0;
    }
    Note * note = malloc(sizeof(Note));
    database->file = fopen(database->name, "rb");
    fseek(database->file, sizeof(DB), SEEK_SET);
    printf("Book: %s\n", database->name);
    printf("\n%s%-3s %-23s %-30s %-11s %-8s%s\n",TEXT_BOLD, "ID", "TITLE", "INFO", "DATE", "TIME", TEXT_DEFAULT);
    for(int i = 0; i < database->count; i++){
        fread(note, database->size, 1, database->file);
        printf("%-3d %-23s %-30s %-11s %-8s\n", note->id,
                console_stringCuted(note->title, 22),
                console_stringCuted(note->info, 29),
                date_string(&note->date),
                time_toString(&note->time));
    }
    putchar('\n');
    fclose(database->file);
}

int db_showint(DB * database){
    if(database->count == 0){
        printf("%s\n\n", "this book is empty (use 'note' to add new notes).");
        return 0;
    }
    int x = 0;
    database->file = fopen(database->name, "rb");
    fseek(database->file, sizeof(DB), SEEK_SET);
    printf("Database: %s\n", database->name);

    for(int i = 0; i < database->count; i++){
        fread(&x, database->size, 1, database->file);
        printf("%-3d", x);
    }
    putchar('\n');
    fclose(database->file);
}

#endif //DATABASE_H