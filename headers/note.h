#ifndef NOTE_H
#define NOTE_H

#include "timenote.h"
#include "date.h"

typedef struct{
	int	   id;
	char * title;
	char * info;
	Time * time;
	Date * date;

}Note;

Note * note_null(){
	Note * note = malloc(sizeof(Note));
	note->id	= 0;
	note->title	= "untitled";
	note->info	= "none";
	note->time	= time_null();
	note->date	= date_null();
	return note;
}

Note * note_new(int id,
				char * title,
				char * info,
				Time * _time,
				Date * date){
	Note * note = malloc(sizeof(Note));
	note->id	= id;
	note->title	= title;
	note->info	= info;
	note->time	= _time;
	note->date	= date;
	return note;
}

void note_show(Note * note){
	printf("id: %d\n", note->id);
	printf("title: %s\n", note->title);
	printf("info: %s\n", note->info);
	time_show(note->time);
	printf(" ");
	date_show(note->date);
	putchar('\n');
}
#endif /* NOTE_H */