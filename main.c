#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"
#include "headers/app.h"
#include "headers/terminalnote.h"

int main(void){
	DB * database = db_new("data.dat", sizeof(Note));
	Note * nota = note_new(23, "Comprar Intrumentos para crear musica",
								"debo ir a comprar instrumentos en la nueva tienda de musica, en el estado lara",
								time_new(12,23,1), date_new(27,1,2018));

	Note * nota2 = note_new(43, "Sacar mi perro a pasear por la calle",
								"debe ser un lunes o un martes, pero siempre con la correa",
								time_new(12,24,25), date_new(28,7,2018));

	Note * nota3 = note_new(12, "Nota con hora actual que se actualizara",
								"se van a actualizar datos, pero aun no funciona",
								time_new(1,1,1), date_new(1,1,1));

	db_add(nota, database);
	db_add(nota2, database);
	db_add(nota3, database);
	db_show(database);
	return 0;
}