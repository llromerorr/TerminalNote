#include "headers/note.h"
#include "headers/console.h"

int main(void){
    //inicializando variables
    Note * note = note_null();
    Time * ntime = time_null();
    Date * date = date_null();

    //definicion de datos
    ntime = time_new(12,25,20);
    date = date_new(13,7,2018);
    note = note_new(27, "my new note", "info of my note", ntime, date);

    //mostrar nota
    note_show(note);

    return EXIT_SUCCESS;
}