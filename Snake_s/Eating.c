#include <time.h>
#include "Windows.h"
#include <stdio.h>
#include "Snake.h"
#define SIZE 15
//snake eating

int eating(char* arr[], struct snake* my_snk, int* length, int* score)
{
	srand((unsigned int)time(NULL));
	int coordinate_x, coordinate_y;
	if (arr[my_snk->head_x][my_snk->head_y] == '*')
	{
		if (*length + 1 == SIZE * SIZE)
		{
			(*length)++;
			(*score)++;
			return 1;
		}
		do
		{
			coordinate_x = 0 + rand() % SIZE;
			coordinate_y = 0 + rand() % SIZE;
		} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == my_snk->tail_x && coordinate_y == my_snk->tail_y));
		arr[coordinate_x][coordinate_y] = '*';
		my_snk->tail_x -= my_snk->wayt_x;
		my_snk->tail_y -= my_snk->wayt_y;
		(*length)++;
		(*score)++;
	}
	return 0;
}