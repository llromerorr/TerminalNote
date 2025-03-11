#ifndef APP_H
#define APP_H

#ifdef _WIN32
    #include <windows.h>
    char * app_getPath()
    {
        char * path = (char*) malloc(sizeof(char) * 1024);
        char * lastslash = NULL;

        GetModuleFileName(0, path, 1000);

        if(!(lastslash = strrchr(path, '\\')))
            if(!(lastslash = strrchr(path, '/')))
                return NULL;

        lastslash[1] = '\0';

        return path;
    }
#else
    #include <unistd.h>

    char * app_getPath()
    {
        static char path[1024];
        char * lastslash = NULL;

        if (readlink("/proc/self/exe", path, sizeof(path) - 1) == -1)
            puts("ERROR PATH");

        if(!(lastslash = strrchr(path, '\\')))
            if(!(lastslash = strrchr(path, '/')))
                return NULL;

        lastslash[1] = '\0';

        return &path[0];
    }
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "terminalnote.h"

void app_help()
{
    printf("\n%s%-10s %-19s %-20s%s\n", TEXT_BOLD, "COMMAND", "ARGUMNETS", "DESCRIPTION", TEXT_DEFAULT);
    printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LCYAN, "note", TEXT_COLOR_FG_DEFAULT, "{title} : {info}", "create new note in current book");
    // printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LWHITE, "show", TEXT_COLOR_FG_DEFAULT, "{book | note id}", "show all or specific note by id (default is all)");
    // printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LWHITE, "find", TEXT_COLOR_FG_DEFAULT, "{text}", "search for text in the content of any note");
    printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LRED, "delete", TEXT_COLOR_FG_DEFAULT, "{note id}", "delete note by id code");

    printf("\n%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LYELLOW, "new", TEXT_COLOR_FG_DEFAULT, "{name}", "create a new book");
    printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LYELLOW, "open", TEXT_COLOR_FG_DEFAULT, "{book}", "open a book");
    printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LRED, "destroy", TEXT_COLOR_FG_DEFAULT, "", "delete the current book and all its notes");
    
    printf("\n%s%-10s%s %-19s %-20s", TEXT_COLOR_FG_LWHITE, "clear", TEXT_COLOR_FG_DEFAULT, "", "clear screen");
    printf("\n%s%-10s%s %-19s %-20s", TEXT_COLOR_FG_LWHITE, "help", TEXT_COLOR_FG_DEFAULT, "", "display help");
    printf("\n%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LRED, "exit", TEXT_COLOR_FG_DEFAULT, "", "go back to system");
    printf("\n%s%s%s\n\n", TEXT_BOLD, "developed by @llromerorr from Venezuela.", TEXT_DEFAULT);
}

void app_errorCommand()
{
    printf("can not recognize this command.\n");
    printf("if you need help type \"%shelp%s\"\n\n", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
}

void app_noteError()
{
    printf("%sSyntax error in note command%s\n\n", TEXT_COLOR_FG_LRED, TEXT_DEFAULT);
    printf("%s%-10s %-19s %-20s%s\n", TEXT_BOLD, "COMMAND", "ARGUMNETS", "DESCRIPTION", TEXT_DEFAULT);
    printf("%s%-10s%s %-19s %-20s\n", TEXT_COLOR_FG_LCYAN, "note", TEXT_COLOR_FG_DEFAULT, "{title} | {info}", "create new note in current book");
    printf("%53s\"%shelp%s\"\n\n", "if you need help type ", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
}

DB *app_getDeafaultBook()
{
    FILE *init_book = fopen("init_book.dat", "r");
    char nameBook[1000];
    DB *book = NULL;

    if (init_book == NULL)
    {
        init_book = fopen("init_book.dat", "w");
        fprintf(init_book, "%s", "myBook");

        book = db_open("myBook");
        if (book == NULL)
            book = db_new("myBook", sizeof(Note));
        fclose(init_book);
        return book;
    }

    fscanf(init_book, "%s", nameBook);
    fclose(init_book);
    book = db_open(nameBook);
    if (book == NULL)
    {
        printf("%s[WARNING]%s '%s' does not exist and will be created.\n", TEXT_COLOR_FG_LYELLOW, TEXT_COLOR_FG_DEFAULT, nameBook);
        printf("Press ENTER to continue...");
        console_pause();
        book = db_new(nameBook, sizeof(Note));
        printf("creating and preparing book... [%sSuccessfully%s]\n\n", TEXT_COLOR_FG_LGREEN, TEXT_DEFAULT);
    }
    return book;
}

int app_note(char **args, int count)
{
    //creating resources
    DB *book = app_getDeafaultBook();
    Note *note = note_null();
    char * title = "";
    char * info = "";

    //Check overload Book
    if (book->count >= 999)
    {
        printf("\n%s%s is full, please delete notes or create a new book.%s\n", TEXT_COLOR_FG_LRED, book->name, TEXT_COLOR_FG_DEFAULT);
        printf("%s%d%s notes, total size %s%.3fMB%s\n\n", TEXT_COLOR_FG_LYELLOW, book->count, TEXT_COLOR_FG_DEFAULT, TEXT_COLOR_FG_LYELLOW, book->count * 0.003515625, TEXT_COLOR_FG_DEFAULT);
        return 0;
    }

    //convert args to title and info
    for (int i = 0; i < count; i++)
    {
        if (strcmp(args[i], ":") == 0)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (j > i + 1)
                    info = console_stringCat(info, " ");
                info = console_stringCat(info, args[j]);
            }
            break;
        }

        if (i > 0)
            title = console_stringCat(title, " ");
        title = console_stringCat(title, args[i]);
    }

    //add info note
    strcpy(note->title, title);
    strcpy(note->info, info);
    note->id = book->count + 1;
    time_copy(&note->time, time_local());
    date_copy(&note->date, date_local());

    db_add(note, book);
    printf("%s%s%snote have been added.%s\n\n", TEXT_BOLD, TEXT_COLOR_FG_GREEN, TEXT_COLOR_FG_DEFAULT, TEXT_DEFAULT);
    // printf("    %s -> %s %ssuccessful%s\n", console_stringCuted(note->title, 10), book->name, TEXT_COLOR_FG_LGREEN, TEXT_DEFAULT);
    // printf("    %s%d%s notes, total size %s%.3fMB%s\n\n", TEXT_COLOR_FG_LYELLOW, book->count, TEXT_COLOR_FG_DEFAULT, TEXT_COLOR_FG_LYELLOW, book->count * 0.003515625, TEXT_COLOR_FG_DEFAULT);
    return 0;
}

int app_newBook(char **args, int count){
    FILE *file;
    DB * book = NULL;

    for(int i = 0; i < count; i++)
    {
        // abrir archivo para ver si existe
        file = fopen(args[i], "r");
        
        // el archivo existe
        if(file)
            printf("'%s' already exists... [%sFailed%s]\n", args[i], TEXT_COLOR_FG_LRED, TEXT_DEFAULT);

        // no existe existe
        else{
            book = db_new(args[i], sizeof(Note));
            printf("'%s' has been created and prepared... [%sSuccess%s]\n", args[i], TEXT_COLOR_FG_LGREEN, TEXT_DEFAULT);
        }
    }
    
    fclose(file);
    putchar('\n');
}

int app_openBook(char **args, int count)
{
    FILE * init_book = fopen("init_book.dat", "w");
    if(!init_book)
        printf("The file init_book.dat has been restored.\n\n");

    fprintf(init_book, "%s\n", args[0]);
    fclose(init_book);
    // printf("%s is open\n\n", args[0]);
    return 0;
}

int app_destroyBook(char **args, int count)
{
    // almacenar libro a borrar
    FILE *init_book = fopen("init_book.dat", "r");
    char nameBook[1000];
    fscanf(init_book, "%s", nameBook);
    fclose(init_book);

    // Eliminar el libro
    if (remove(nameBook) == 0) {
        // cambiar al libro por defecto
        char *defaultBook[] = {"myBook"};
        app_openBook(defaultBook, 1);
        
        // mostrar mensaje de completado
        printf("The book %s has been successfully deleted.\n\n", nameBook);
    }
    
    else {
        perror("Error deleting the book, please verify that the book actually exists.");
    }

    return 0;
}

int app_show(char **args, int count)
{
    if(count == 0)
        db_showAll(app_getDeafaultBook());
    else
    {
        DB * database = NULL;

        if (islower(args[0][0]) || isupper(args[0][0]))
        {
            database = db_open(args[0]);

            if(database == NULL)
            {
                printf("error \"%s\" do not exist.\n\n", args[0]);
                return -1;
            }

            else if(database->count == 0)
            {
                printf("this book is empty (use '%snote%s' to add new notes).\n\n",
                        TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
                return 0;
            }

            else if (count == 1) {
                db_showAll(database);
                return 0;
            }    

            for(int i = 1; i < count; i++)
            {
                Note * note = (Note*) malloc(sizeof(Note));
                int id = atoi(args[i]);

                if(id > database->count || id < 1)
                {
                    printf("the note id do not exist.\n\n");
                    return 0;
                }

                database->file = fopen(database->name, "rb");
                fseek(database->file, sizeof(DB) + (sizeof(Note) * (id - 1)), SEEK_SET);
                fread(note, database->size, 1, database->file);
                
                printf("\n%s%s%s\n\n", TEXT_BOLD, console_stringToUpper(note->title), TEXT_DEFAULT);
                printf("%s\n\n", note->info);
                printf("Book: %s\nID:   %i\nDate: %s\nTime: %s\n\n\n", database->name, note->id, date_string(&note->date), time_toString(&note->time));

                fclose(database->file);
            }
        }

        else
        {
            DB * database = app_getDeafaultBook();

            for(int i = 0; i < count; i++)
            {
                Note * note = (Note*) malloc(sizeof(Note));
                int id = atoi(args[i]);

                if(id > database->count || id < 1)
                {
                    printf("the note id do not exist.\n\n");
                    return 0;
                }

                database->file = fopen(database->name, "rb");
                fseek(database->file, sizeof(DB) + (sizeof(Note) * (id - 1)), SEEK_SET);
                fread(note, database->size, 1, database->file);
                
                printf("\n%s%s%s\n\n", TEXT_BOLD, console_stringToUpper(note->title), TEXT_DEFAULT);
                printf("%s\n\n", note->info);
                printf("Book: %s\nID:   %i\nDate: %s\nTime: %s\n\n\n", database->name, note->id, date_string(&note->date), time_toString(&note->time));

                fclose(database->file);
            }
        }
    }
    
}

int app_remove(char **args, int count)
{
    DB * book = app_getDeafaultBook();
    int * ids = (int*) malloc(sizeof(int) * count);

    for(int i = 0; i < count; i++)
        ids[i] = atoi(args[i]);

    if(book == NULL)
    {
        printf("error \"%s\" do not exist.\n\n", book->name);
        return -1;
    }

    else if(book->count == 0)
    {
        printf("this book is empty (use '%snote%s' to add new notes).\n\n",
                TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
    }
    
    for(int i = 0; i < count; i++)
    {
        if(ids[i] > book->count || ids[i] < 1)
            printf("the note with id '%i' do not exist.\n", ids[i]);
        else
            printf("[%i]|######################>| 100%\n", ids[i]);
    }

    db_remove(book, ids, count);
    printf("\n");
    
    return 0;
}

int app_scanInput(char **arguments, int count)
{
    if (strcmp(arguments[0], "note") == 0)
        if (count > 1)
            app_note(arguments + 1, count - 1);
        else
            app_noteError();

    else if (strcmp(arguments[0], "exit") == 0)
        exit(-1);

    else if (strcmp(arguments[0], "help") == 0)
        app_help();
    
    else if (strcmp(arguments[0], "new") == 0)
        app_newBook(arguments + 1, count - 1);

    else if (strcmp(arguments[0], "open") == 0)
        app_openBook(arguments + 1, count - 1);
        
    else if (strcmp(arguments[0], "clear") == 0)
        console_clear();

    else if (strcmp(arguments[0], "show") == 0)
        app_show(arguments + 1, count - 1);

    else if (strcmp(arguments[0], "delete") == 0)
        app_remove(arguments + 1, count - 1);

    else if (strcmp(arguments[0], "destroy") == 0)
        app_destroyBook(arguments + 1, count - 1);

    //Temporaly fuction to test path
    // else if (strcmp(arguments[0], "path") == 0)
    //     printf("path: %s\n", app_getPath());

    else
        app_errorCommand();

    return 0;
}

int app_interactiveSession()
{
    //Show header application
    printf("%sTerminalNote%s %s [%s]\n", TEXT_BOLD, TEXT_DEFAULT, _APPLICATION_VERSION_, time_GetLocalTime());
    printf("if you need help type \"%shelp%s\"\n\n", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);

    //Creating resources
    char *input = (char*) malloc(sizeof(char) * 1000);
    char **arguments = NULL;
    int argumentsCount = 0;
    DB *book = app_getDeafaultBook();

    //Getting username
    char *user = getenv("USER");
    if (user == NULL)
        user = "tnote";

    //Start interactive session
    do
    {
        book = app_getDeafaultBook();
        printf("%s%s%s[%s%s%s%s%s]: ", TEXT_COLOR_FG_LWHITE, user, TEXT_COLOR_FG_DEFAULT, TEXT_BOLD, TEXT_COLOR_FG_LBLUE, book->name, TEXT_COLOR_FG_DEFAULT, TEXT_DEFAULT);
        fgets(input, 1000, stdin);
        
        //converting input string to array of string (arguments)
        arguments = console_splitString(input, &argumentsCount);

    } while (!app_scanInput(arguments, argumentsCount));
}

#endif /* APP_H */