#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void init_lvl(char* arr[], struct snake* snk, struct list_edge* Edge, int* length, int* flag);
int lvl(char* arr[], char* level);

#define open(pointer, name, mode)\
	if ((pointer = fopen(name, mode)) == NULL)\
	{\
		puts("Can't open file.");\
		return 1;\
	}