#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int day;
	int month;
	int year;
} Date;

char* date_string(Date * date){
	char* dateString = (char*) malloc(sizeof(char) * 15);
	char bridge[8];

	sprintf(bridge, "%.2d/", (*date).day);
	strcpy(dateString, bridge);
	sprintf(bridge, "%.2d/", (*date).month);
	strcat(dateString, bridge);
	sprintf(bridge, "%.4d", (*date).year);
	strcat(dateString, bridge);

	return dateString;
}

void date_show(Date * date){
	printf("%.2d/", date->day);
	switch(date->month){
		case 1: printf("jan/"); break;
		case 2: printf("feb/"); break;
		case 3: printf("mar/"); break;
		case 4: printf("apr/"); break;
		case 5: printf("may/"); break;
		case 6: printf("jun/"); break;
		case 7: printf("jul/"); break;
		case 8: printf("aug/"); break;
		case 9: printf("sep/"); break;
		case 10:printf("oct/"); break;
		case 11:printf("nov/"); break;
		case 12:printf("dec/"); break;
		default: printf("null/");
	}
	printf("%.4d", date->year);
}

Date * date_local(){
	Date * date = malloc(sizeof(Date));
	time_t __time = time(0);
    struct tm *tlocal = localtime(&__time);
	date->day = tlocal->tm_mday;
	date->month = tlocal->tm_mon + 1;
	date->year = tlocal->tm_year + 1900;
	return date;
}

int date_toDays(Date * date){
	return ((*date).year * 365) + (((*date).month) * 30) + (*date).day;
}

int date_check(Date * date){
	if((*date).month < 1 || (*date).month > 12)   return 0;
	if((*date).day < 1 || (*date).day > 31) 	    return 0;
	if((*date).year < 0) 				        return 0;

	if ((*date).month == 4 || (*date).month == 6 || (*date).month == 9 || (*date).month == 11)
		if((*date).day > 30) return 0;
	if((((*date).year % 4 == 0) && ((*date).year % 100 != 0)) || ((*date).year % 400 == 0)){
		if((*date).month == 2)
			if((*date).day > 29) return 0;
	}
	else if((*date).month == 2)
		if((*date).day > 28) return 0;

	return 1;
}

int date_compare(Date * date1, Date * date2)
{
	if((*date1).year == (*date2).year)
	{
		if((*date1).month == (*date2).month)
		{
			if((*date1).day == (*date2).day)      return  0;
			else if((*date1).day > (*date2).day)  return  1;
			else if((*date1).day < (*date2).day)  return -1;
		}
		else if((*date1).month > (*date2).month)  return  1;
		else if((*date1).month < (*date2).month)  return -1;
	}
	else if((*date1).year > (*date2).year)        return  1;
	else if((*date1).year < (*date2).year)        return -1;
	return 0;
}

void date_copy(Date * date1, Date * date2){
	date1->day = date2->day;
	date1->month = date2->month;
	date1->year = date2->year;
}

Date * date_new(int day, int month, int year){
	Date * date = (Date*) malloc(sizeof(Date));
	date->day = day;
	date->month = month;
	date->year = year;
	return date;
}

Date * date_null(){
	Date * date = (Date*) malloc(sizeof(Date));
	date->day = 0;
	date->month = 0;
	date->year = 0;
	return date;
}

//-------------------Setters and Getters---------------------

void date_set_day(Date * date, int day){
	date->day = day;
}

void date_set_month(Date * date, int month){
	date->month = month;
}

void date_set_year(Date * date, int year){
	date->year = year;
}

int date_get_day(Date * date){
	return date->day;
}

int date_get_month(Date * date){
	return date->month;
}

int date_get_year(Date * date){
	return date->year;
}

//--------------------------Others---------------------------
int date_daysBetween(Date * t1, Date * t2){
	const int monthDays[12] = {31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31};
	
	int lp1 = (t1->month <= 2) 
				? (t1->year-1)/4 - (t1->year-1)/100 + (t1->year-1)/400
				: t1->year/4 - t1->year/100 + t1->year/400;

	int lp2 = (t2->month <= 2) 
				? (t2->year-1)/4 - (t2->year-1)/100 + (t2->year-1)/400
				: t2->year/4 - t2->year/100 + t2->year/400;
 
	long int n1 = t1->year*365 + t1->day;
	for (int i=0; i<t1->month - 1; i++)
		n1 += monthDays[i];
	
	n1 += lp1;

	long int n2 = t2->year*365 + t2->day;
	for (int i=0; i<t2->month - 1; i++)
		n2 += monthDays[i];
	
	n2 += lp2;
	return (n2 - n1);
}

#endif /* DATE_H */