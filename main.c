#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"
#include "headers/app.h"
#include "headers/terminalnote.h"

int main(void){
    char * input = malloc(sizeof(char) * 1000);
    
    DB * book = db_open("myBook");
    if(book == NULL){
        book = db_new("myBook", sizeof(Note));
        Note * note = note_new(23, "Nota de prueba", "esta nota es para testear la aplicaion", time_new(12,23,5), date_new(13,7,2018));
        db_add(note, book);
    }
    
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
    return EXIT_SUCCESS;
}