
#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void console_input_int(int* var){
	char 	input[12];
	char*	point;

	fgets(input, 12, stdin);
	point = strchr(input, '\n');

	if(point == NULL) while(getchar()!= '\n');
	*var = atoi(input);
}

void console_clear(){
    system("cls");
}

void console_pause(){
	while(getchar()!= '\n');
}

#endif /* CONSOLE_H */