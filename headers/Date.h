#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int Day;
	int Month;
	int Year;
} Date;

char* Date_ToString(Date * date){
	char* DateString = (char*) malloc(sizeof(char) * 15);
	char Bridge[8];

	sprintf(Bridge, "%.2d/", (*date).Day);
	strcpy(DateString, Bridge);
	sprintf(Bridge, "%.2d/", (*date).Month);
	strcat(DateString, Bridge);
	sprintf(Bridge, "%.4d", (*date).Year);
	strcat(DateString, Bridge);

	return DateString;
}

int Date_ToDays(Date * date){
	return ((*date).Year * 365) + (((*date).Month) * 30) + (*date).Day;
}

int Date_Check(Date * date){
	if((*date).Month < 1 || (*date).Month > 12)   return 0;
	if((*date).Day < 1 || (*date).Day > 31) 	    return 0;
	if((*date).Year < 0) 				        return 0;

	if ((*date).Month == 4 || (*date).Month == 6 || (*date).Month == 9 || (*date).Month == 11)
		if((*date).Day > 30) return 0;
	if((((*date).Year % 4 == 0) && ((*date).Year % 100 != 0)) || ((*date).Year % 400 == 0)){
		if((*date).Month == 2)
			if((*date).Day > 29) return 0;
	}
	else if((*date).Month == 2)
		if((*date).Day > 28) return 0;

	return 1;
}

int Date_Compare(Date * Date1, Date * Date2)
{
	if((*Date1).Year == (*Date2).Year)
	{
		if((*Date1).Month == (*Date2).Month)
		{
			if((*Date1).Day == (*Date2).Day)      return  0;
			else if((*Date1).Day > (*Date2).Day)  return  1;
			else if((*Date1).Day < (*Date2).Day)  return -1;
		}
		else if((*Date1).Month > (*Date2).Month)  return  1;
		else if((*Date1).Month < (*Date2).Month)  return -1;
	}
	else if((*Date1).Year > (*Date2).Year)        return  1;
	else if((*Date1).Year < (*Date2).Year)        return -1;
	return 0;
}

void Date_Copy(Date * date1, Date * date2){
	date1->Day = date2->Day;
	date1->Month = date2->Month;
	date1->Year = date2->Year;
}

Date * Date_New(int Day, int Month, int Year){
	Date * date = (Date*) malloc(sizeof(Date));
	date->Day = Day;
	date->Month = Month;
	date->Year = Year;
	return date;
}

Date * Date_Null(){
	Date * date = (Date*) malloc(sizeof(Date));
	date->Day = 0;
	date->Month = 0;
	date->Year = 0;
	return date;
}

//-------------------Setters and Getters---------------------

void Date_Set_Day(Date * date, int Day){
	date->Day = Day;
}

void Date_Set_Month(Date * date, int Month){
	date->Month = Month;
}

void Date_Set_Year(Date * date, int Year){
	date->Year = Year;
}

int Date_Get_Day(Date * date){
	return date->Day;
}

int Date_Get_Month(Date * date){
	return date->Month;
}

int Date_Get_Year(Date * date){
	return date->Year;
}

//--------------------------Others---------------------------
int Date_DaysBetween(Date * t1, Date * t2){
	const int monthDays[12] = {31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31};
	
	int lp1 = (t1->Month <= 2) 
				? (t1->Year-1)/4 - (t1->Year-1)/100 + (t1->Year-1)/400
				: t1->Year/4 - t1->Year/100 + t1->Year/400;

	int lp2 = (t2->Month <= 2) 
				? (t2->Year-1)/4 - (t2->Year-1)/100 + (t2->Year-1)/400
				: t2->Year/4 - t2->Year/100 + t2->Year/400;
 
	long int n1 = t1->Year*365 + t1->Day;
	for (int i=0; i<t1->Month - 1; i++)
		n1 += monthDays[i];
	
	n1 += lp1;

	long int n2 = t2->Year*365 + t2->Day;
	for (int i=0; i<t2->Month - 1; i++)
		n2 += monthDays[i];
	
	n2 += lp2;
	return (n2 - n1);
}

#endif /* DATE_H */