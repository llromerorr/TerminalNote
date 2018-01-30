#include "headers/note.h"
#include "headers/console.h"
#include "headers/database.h"

int main(void){
	//creating database
	DB * database = db_new("ndata.dat", sizeof(int));
	
	//adding elements
	for(int i = 1; i < 10; i++)
		db_add(&i, database);
	
	int otherNumber = 45;
	db_add(&otherNumber, database);

	//linking other database
	DB * new = db_open(database->name);
	int morenumber = 12;
	db_add(&morenumber, new);

	//show database
	db_show(new);

	return 0;
}

// OUTPUT
// Database: ndata.dat
// 1   2   3   4   5   6   7   8   9   45  12
//commit form visual studio code