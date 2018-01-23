#include "headers/Note.h"
#include "headers/Console.h"

int main(void){
    Note hola;
    hola.Title = "Crear cuenta en freelancer";
    //hola.Title = "Nuevo titulo";
    int len = strlen(hola.Title);
    puts(hola.Title);
    printf("length: %d", len);
    Console_Pause();
    return EXIT_SUCCESS;
}