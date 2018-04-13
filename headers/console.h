#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __linux__
	void console_clear(){
		printf("%s", "\033[2J\033[;H");
	}
#elif _WIN32
	void console_clear(){
		system("cls");
	}
#endif

void console_input_int(int* var){
	char 	input[12];
	char*	point;

	fgets(input, 12, stdin);
	point = strchr(input, '\n');

	if(point == NULL) while(getchar()!= '\n');
	*var = atoi(input);
}

void console_pause(){
	while(getchar()!= '\n');
}

char * console_stringCuted(char * text, int count){
	char * output = (char*) malloc(sizeof(char) * (count + 1));
	int len = strlen(text);

	if(len <= count)
		return text;
	else{
		for(int i = 0; i < count -2; i++)
			output[i] = text[i];
		for(int i = count -2; i < count; i++)
			output[i] = '.';
		output[count] = '\0';
		return output;
	}
	return NULL;
}

char * console_clearString(char * input){
	int inputPosition = 0;
	int outputCount = 1;
	char * output = (char*) malloc(sizeof(char));

	//Find first char in the string
	for(int i = 0;; i++){
		if(input[i] == '\0' || input[i] == '\n')
			return "";

		else if(input[i] != ' '){
			inputPosition = i;
			break;
		}
	}

	//Clear spaces between words
	for(int i = inputPosition; i < strlen(input); i++){
		if(input[i] == ' '){
			outputCount++;
			output = (char*) realloc(output, sizeof(char) * outputCount);
			output[outputCount - 2] = input[i];
			for(; input[i] == ' '; i++);
			i--;
		}
		else if(input[i] != '\0' && input[i] != '\n'){
			outputCount++;
			output = (char*) realloc(output, sizeof(char) * outputCount);
			output[outputCount - 2] = input[i];
		}
	}

	//add \0 character to end string
	if(output[outputCount - 2] == ' ')
		output[outputCount - 2] = '\0';
	else 
		output[outputCount - 1] = '\0';
	return output;
}

#endif /* CONSOLE_H */