#ifndef NOTE_H
#define NOTE_H

#include "timenote.h"
#include "date.h"

typedef struct{
    int     id;
    char    title[500];
    char    info[3000];
    Time    time;
    Date    date;
}Note;

Note * note_null(){
    Note * note = malloc(sizeof(Note));
    note->id = 0;
    strcpy(note->title, "none");
    strcpy(note->info, "empty content");
    note->time.hour = 0;
    note->time.minute = 0;
    note->time.second = 0;
    note->date.day = 0;
    note->date.month = 0;
    note->date.year = 0;
    return note;
}

Note * note_new(int id,
                char * title,
                char * info,
                Time * _time,
                Date * date){
    Note * note = malloc(sizeof(Note));
    note->id	= id;
    strcpy(note->title, title);
    strcpy(note->info, info);
    note->time.hour = _time->hour;
    note->time.minute = _time->minute;
    note->time.second = _time->second;
    note->date.day = date->day;
    note->date.month = date->month;
    note->date.year = date->year;
    return note;
}

void note_show(Note * note){
    printf("%-79s\n\n", note->title);
    printf("%s\n\n", note->info);
    date_show(&note->date);
    printf(" [%s] [ID: %d]\n\n", time_toString(&note->time), note->id);
}
#endif /* NOTE_H */