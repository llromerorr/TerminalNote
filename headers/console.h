#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>

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

char * console_stringCuted(char * text, int count){
	char * output = malloc(sizeof(char) * count);
	int len = strlen(text);

	if(len <= count)
		return text;
	else{
		for(int i = 0; i < count -2; i++)
			output[i] = text[i];
		for(int i = count -2; i < count; i++)
			output[i] = '.';
		return output;
	}
}

#endif /* CONSOLE_H */