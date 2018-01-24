#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int hour;
	int minute;
	int second;
}Time;

//----------------------Fundamentals-------------------------//
Time * time_null(){
	Time * _time = (Time*) malloc (sizeof(Time));
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

void time_show(Time * _time){
	printf("%d:%d:%d", _time->hour, _time->minute, _time->second);
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