#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"
#include "headers/app.h"
#include "headers/terminalnote.h"

int main(void){
	DB * database = db_new("data.dat", sizeof(Note));
	Note * nota = note_new(23, "Comprar Intrumentos",
								"debo ir a comprar instrumentos",
								time_new(12,23,1), date_new(27,1,2018));

	Note * nota2 = note_new(43, "Sacar mi perro a pasear",
								"debe ser un lunes o un martes",
								time_new(12,24,25), date_new(28,7,2018));
	db_add(nota, database);
	db_add(nota2, database);
	db_show(database);
	return 0;
}