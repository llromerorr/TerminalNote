#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    FILE *  file;
    size_t  size;
    char *  name;
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
        printf("%s %s", "can't open file", name);
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
    int n = 0;
    database->file = fopen(database->name, "rb");
    fseek(database->file, sizeof(DB), SEEK_SET);
    printf("Database: %s\n", database->name);
    for(int i = 0; i < database->count; i++){
        fread(&n, database->size, 1, database->file);
        printf("%-4d", n);
    }
    putchar('\n');
    fclose(database->file);
}

#endif //DATABASE_H