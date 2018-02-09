#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"
#include "headers/app.h"
#include "headers/terminalnote.h"

int main(void){
    char * input = malloc(sizeof(char) * 1000);
    
    DB * book = db_open("myBook");
    if(book == NULL)
        book = db_new("myBook", sizeof(Note));
    
    char * user = getenv("USER");
    if(user == NULL)
        user = "user";

    printf("%sTerminalNote%s %s [%s]\n",TEXT_BOLD, TEXT_DEFAULT,_APPLICATION_VERSION_, time_GetLocalTime());
    printf("if you need help type \"%shelp\"%s\n\n", TEXT_COLOR_FG_LMAGENTA, TEXT_DEFAULT);
    while(true){
        printf("%s%s%s[%s%s%s%s%s]: ", TEXT_COLOR_FG_LWHITE, user, TEXT_COLOR_FG_DEFAULT,
                TEXT_BOLD, TEXT_COLOR_FG_LGREEN, book->name, TEXT_COLOR_FG_DEFAULT, TEXT_DEFAULT);

        fgets(input, 100, stdin);
        if(strstr(input, "help") != NULL)
            app_help();
        else if(strcmp(input, "show\n")==0)
            db_show(book);
        else if(strcmp(input, "clear\n")==0)
            console_clear();
        else if(strcmp(input, "exit\n")==0)
            exit(-1);
        else 
            app_errorCommand();
    }
    return 0;
}
