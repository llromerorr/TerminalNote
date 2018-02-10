#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"
#include "headers/app.h"
#include "headers/terminalnote.h"

int main(void){
    char command[10];
    char * input = malloc(sizeof(char) * 1000);
    
    DB * book = db_open("myBook");
    if(book == NULL)
        book = db_new("myBook", sizeof(Note));
    
    char * user = getenv("USER");
    if(user == NULL)
        user = "user";

    printf("%sTerminalNote%s %s [%s]\n",TEXT_BOLD, TEXT_DEFAULT,_APPLICATION_VERSION_, time_GetLocalTime());
    printf("if you need help type \"%shelp\"%s\n\n", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
    while(1){
        printf("%s%s%s[%s%s%s%s%s]: ", TEXT_COLOR_FG_LWHITE, user, TEXT_COLOR_FG_DEFAULT, TEXT_BOLD, 
                                        TEXT_COLOR_FG_LBLUE, book->name, TEXT_COLOR_FG_DEFAULT, TEXT_DEFAULT);
        
        strcpy(command, "");
        strcpy(input, "");
        fgets(input, 4000, stdin);
        sscanf(input, "%9s", command);

        if(strcmp(command, "note") == 0)
            app_note(input, book);
        else if(strcmp(command, "show") == 0)
            db_show(book);
        else if(strcmp(command, "help") == 0)
            app_help();
        else if(strcmp(command, "clear") == 0)
            console_clear();
        else if(strcmp(command, "exit") == 0)
            exit(0);
else
            app_errorCommand();
}
    return 0;
}