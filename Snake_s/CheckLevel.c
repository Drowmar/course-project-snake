#include <stdio.h>
#include <conio.h>
#include "Windows.h"
#include "Levels.h"
#define MAX_LONG 15
#define SIZE 15

//check the length of the snake to initialize level
int check_level(COORD position, HANDLE hConsole, int *level, char* arr[], struct snake* snk, struct list_edge* Edge, int* length, int* flag)
{
	extern int score;
	int i, j, flag_level = 0;
	if (*length == MAX_LONG)
	{
		flag_level = 0;
		switch (*level)
		{
		case 1:
			if (lvl(arr, "level2.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 2;

			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		case 2:
			if (lvl(arr, "level3.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 3;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		case 3:
			if (lvl(arr, "level4.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 4;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		case 4:
			if (lvl(arr, "level5.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 5;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		case 5:
			if (lvl(arr, "level6.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 6;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		case 6:
			if (lvl(arr, "level7.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 7;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		case 7:
			if (lvl(arr, "level8.txt") == 1)
			{
				flag_level = 1;
				break;
			}
			*level = 8;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
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
			*flag = 1;
			system("cls");
			puts("YOU WIN!!!\nInput ENTER to continue.");
			char temp;
			do 
			{
				temp = _getch();
			}while((int)temp != 13);
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, snk, Edge, length, flag);
			score++;
			break;
		}
	}
	return flag_level;
}