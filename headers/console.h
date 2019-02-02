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

char ** console_splitString(char * input, int * count)
{
	int argc = 0;
	char * current = NULL;
	char ** vector = (char**) malloc(sizeof(char*));

	for(int i = 0; i < strlen(input); i++)
	{
		//skip spaces before first argument
		if(input[i] == ' ' && argc == 0)
			continue;

		//break loop
		else if(input[i] == '\n' || input[i] == '\0')
			break;

		//append new argument
		else if(input[i] != ' ')
		{
			int tempCount = 0;
			current = (char*) malloc(sizeof(char));

			for(int j = 0; input[i + j] != ' ' && input[i + j] != '\n'; j++, tempCount = j)
			{
				current[j] = input[i + j];
				current = (char*) realloc(current, sizeof(char) * (j + 2));
			}

			current[tempCount] = '\0';
			vector[argc] = current;
			vector = (char**) realloc(vector, sizeof(char*) * (argc + 2));
			argc++;
			i += tempCount;
		}
	}
	
	*count = argc;
	return vector;
}

char * console_stringCat(char * string1, char * string2)
{
	int lenstr1 = (string1 == NULL) ? 0 : strlen(string1);
	int lenstr2 = (string2 == NULL) ? 0 : strlen(string2);

	//Cheking string lengths
	if(lenstr1 + lenstr2 == 0)
		return NULL;

	char * stringTemp = (char*) malloc(sizeof(char) * (lenstr1 + lenstr2 + 1));
	
	//copy string1
	for(int i = 0; i < lenstr1; i++)
		stringTemp[i] = string1[i];
	
	//copy string2
	for(int i = lenstr1; i < lenstr1 + lenstr2; i++)
		stringTemp[i] = string2[i - lenstr1];

	//append endline
	stringTemp[lenstr1 + lenstr2] = '\0';

	return stringTemp;
}

#endif /* CONSOLE_H */