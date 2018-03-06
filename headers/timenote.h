#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int hour;
	int minute;
	int second;
}Time;

//--------------------------Optional--------------------------//
char * time_GetLocalTime(){
	time_t _time = time(0);
    struct tm *tlocal = localtime(&_time);
    char * output = malloc(sizeof(char) * 128);
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    return output;
}

Time * time_local(){
	Time * _time = malloc(sizeof(Time));
	time_t __time = time(0);
    struct tm *tlocal = localtime(&__time);
	_time->hour = tlocal->tm_hour;
	_time->minute = tlocal->tm_min;
	_time->second = tlocal->tm_sec;
	return _time;
}
//----------------------Fundamentals-------------------------//
Time * time_null(){
	Time * _time = malloc (sizeof(Time));
	_time -> hour = 0;
	_time -> minute = 0;
	_time -> second = 0;
	return _time;
}

Time * time_new(int hour, int minute, int second){
	Time * _time = (Time*) malloc (sizeof(Time));
	_time -> hour = hour;
	_time -> minute = minute;
	_time -> second = second;
	return _time;
}

int time_copy(Time * to, Time * from){
	to->hour = from->hour;
	to->minute = from->minute;
	to->second = from->second;
	return 0;
}

char * time_toString(Time * _time){
	char * output = malloc(sizeof(char) * 100);
	sprintf(output, "%.2d:%.2d:%.2d", _time->hour, _time->minute, _time->second);
	return output;
}
//-------------------Setters and Getters---------------------//

void time_set_hour(Time * _time, int hour){
	_time->hour = hour;
}

void time_set_minute(Time * _time, int minute){
	_time->minute = minute;
}

void time_set_second(Time * _time, int second){
	_time->second = second;
}

int time_get_hour(Time * _time){
	return _time->hour;
}

int time_get_minute(Time * _time){
	return _time->minute;
}

int time_get_second(Time * _time){
	return _time->second;
}

#endif //TIME_H