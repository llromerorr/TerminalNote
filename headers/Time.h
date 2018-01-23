#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int Hour;
	int Minute;
	int Second;
}Time;

//-------------------Setters and Getters---------------------//

void Time_Set_Hour(Time * _time, int Hour){
	_time->Hour = Hour;
}

void Time_Set_Minute(Time * _time, int Minute){
	_time->Minute = Minute;
}

void Time_Set_Second(Time * _time, int Second){
	_time->Second = Second;
}

int Time_Get_Hour(Time * _time){
	return _time->Hour;
}

int Time_Get_Minute(Time * _time){
	return _time->Minute;
}

int Time_Get_Second(Time * _time){
	return _time->Second;
}

#endif //TIME_H