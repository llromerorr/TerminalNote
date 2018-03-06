#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"
#include "headers/app.h"
#include "headers/terminalnote.h"
#include "./headers/sds.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
        app_scanInput(argv + 1, argc - 1);
    else
        app_interactiveSession();
    return 0;
}