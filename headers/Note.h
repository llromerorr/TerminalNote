#ifndef NOTE_H
#define NOTE_H

#include "Time.h"
#include "Date.h"

typedef struct{
	int id;
	char * title;
	char * info;
	Time * time;
	Date * date;

} Note;

int Note_MakeNote(){

}

#endif /* NOTE_H */