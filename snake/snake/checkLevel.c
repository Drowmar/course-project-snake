#include <stdlib.h>
#include "Windows.h"
#include "levels.h"
#define MAX_LONG 10
#define SIZE 15

//check the length of the snake to initialize level
int checkLevel(COORD position, HANDLE hConsole, int *level, char* arr[], int* head_x, int* head_y, int* tail_x, int* tail_y, int* coordinate_x, int* coordinate_y, int* way_x, int* way_y, int* wayt_x, int* wayt_y, struct ListEdge* Edge, int* length, int* flag)
{
	extern int score;
	int i, j, flag_level = 0;
	if (*length == MAX_LONG)
	{
		flag_level = 0;
		switch (*level)
		{
		case 1:
			if (lvl_2(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 2;

			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 2:
			if (lvl_3(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 3;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 3:
			if (lvl_4(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 4;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 4:
			if (lvl_5(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 5;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 5:
			if (lvl_6(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 6;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 6:
			if (lvl_7(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 7;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 7:
			if (lvl_8(arr) == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 8;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		case 8:
			i = 0;
			j = 0;
			for (i = 0; i < SIZE; i++)
			{
				for (j = 0; j < SIZE; j++)
				{
					arr[i][j] = '.';
				}
			}
			*level = 9;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, head_x, head_y, tail_x, tail_y, coordinate_x, coordinate_y, way_x, way_y, wayt_x, wayt_y, Edge, length, flag);
			score++;
			break;
		}
	}
	return flag_level;
}