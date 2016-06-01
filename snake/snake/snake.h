#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structure for snake
struct snake
{
	int head_x;
	int head_y;
	int tail_x;
	int tail_y;
	int wayh_x;
	int wayh_y;
	int wayt_x;
	int wayt_y;
};

//structure for bullets
struct war
{
	int wayv_x;
	int wayv_y;
	int coord_x;
	int coord_y;
};

#define memory(pointer, size, type)\
	pointer = (type*)malloc(size * sizeof(type)); \
	if (pointer == NULL){\
		puts("Out if memory.");\
		return;\
	}

#define memory_r(pointer, size, type)\
	pointer = (type*)realloc(pointer, size * sizeof(type)); \
	if (pointer == NULL){\
		free_all(arr, num_v, &Edge);\
		return; \
	}

#define memory_arr(pointer)\
	pointer = (char**)malloc(SIZE * sizeof(char*)); \
	if (pointer == NULL)\
	{\
		puts("Out if memory."); \
		free(pointer); \
		return;\
	}\
	for (i = 0; i < SIZE; i++)\
	{\
		pointer[i] = NULL; \
		pointer[i] = (char*)malloc(SIZE * sizeof(char)); \
		if (pointer[i] == NULL)\
		{\
			printf("ERROR");\
			for (j = 0; j <= i; j++)\
			{\
				free(pointer[j]); \
			}\
			free(pointer); \
			return;\
		}\
	}