#include <stdio.h>
#include <conio.h>
#include "stack.h"
#include "writeArr.h"
#include "snake.h"
#include "Windows.h"
#define SIZE 15

//level initialization
void init_lvl(char* arr[], struct snake* snk, struct list_edge* Edge, int* length, int* flag)
{
	srand((unsigned int)time(NULL));
	int coordinate_x, coordinate_y;
	snk->head_x = 6;
	snk->head_y = 1;
	arr[snk->head_x][snk->head_y] = '>';
	snk->tail_x = snk->head_x;
	snk->tail_y = snk->head_y;
	do
	{
		coordinate_x = 0 + rand() % SIZE;
		coordinate_y = 0 + rand() % SIZE;
	} while (arr[coordinate_x][coordinate_y] != '.');
	arr[coordinate_x][coordinate_y] = '*';

	snk->wayh_x = 0;
	snk->wayh_y = 1;
	snk->wayt_x = snk->wayh_x;
	snk->wayt_y = snk->wayh_y;
	*length = 1;
	*flag = 0;

	Clear(Edge);
	Init(Edge);
	write_arr(arr);
	printf("Input ENTER to start.\n");
	while ((int)_getch() != 13){}
	system("cls");
	return;
}

//creating fields for a certain level
int lvl(char* arr[], char* level)
{
	int i, j;
	FILE *f;
	char ch = ' ';
	if ((f = fopen(level, "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f, "%c", &ch);
	}
	fclose(f);
	return 0;
}