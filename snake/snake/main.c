#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "Windows.h"
#include "levels.h"
#include "snake.h"
#include "stack.h"
#include "writeArr.h"
#include "read.h"
#include "checkLevel.h"
#include "complexity.h"
#include "eating.h"
#include "hitBullet.h"
#define SIZE 15

//snake drawing selection
char kind_edge(int x, int y)
{
	if (x == -1 && y == 0)
		return '^';
	if (x == 0 && y == -1)
		return '<';
	if (x == 0 && y == 1)
		return '>';
	if (x == 1 && y == 0)
		return 'V';
	return 'o';
}

void write_help()
{
	puts("Game snake.\nYou control the snake, but the snake is moving itself.");
	puts("Your goal is to eat the food and grow as much as possible.");
	puts("You win when your snake will occupy the entire field.\nControl:\nw - up; \na - right; \nd - left; \ns - down;");
	puts("If you want pause / exit - press 0(number).\nIf you choose modern, you can shoot pressing the SPACE.");
}

//deallocation
void Free(char *arr[], struct war* num_v, struct list_edge *edge)
{
	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(num_v);
	Clear(edge);
	return;
}

int score = 1;
void main(void)
{
	struct war* num_v = NULL;
	struct snake my_snk;
	char** arr = NULL;
	int flag_level = 0, kind = 0, num_of_v = 0, tmp_x, tmp_y;
	int j1, level, difficulty, i, j, i1, coordinate_x, coordinate_y;
	int flag, length;
	char press, main_flag = 0; 
	write_help();
	struct list_edge Edge;
	Init(&Edge);
	srand((unsigned int)time(NULL));
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 0;
	position.Y = 0;
	do
	{
		//memory allocation
		main_flag = 0;
		num_of_v = 0;
		num_v = (struct war*)malloc(0 * sizeof(struct war));
		if (num_v == NULL)
		{
			puts("Out if memory.");
			return;
		}

		arr = (char**)malloc(SIZE * sizeof(char*));
		if (arr == NULL)
		{
			printf("ERROR");
			free(arr);
			return;
		}
		for (i = 0; i < SIZE; i++)
		{
			arr[i] = NULL;
			arr[i] = (char*)malloc(SIZE * sizeof(char));
			if (arr[i] == NULL)
			{
				printf("ERROR");
				for (j = 0; j <= i; j++)
				{
					free(arr[j]);
				}
				free(arr);
				return;
			}
		}
		
		if ((difficulty = complexity()) == 1)
			break;
		//choose the type of game
		printf("Input kind of game.\n1 - classic.\n2 - modern.\n");
		do
		{
			kind = read();
		} while (kind != 1 && kind != 2 && kind != 0);
		if (kind == 0)
			break;

		//initialize the game field
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				arr[i][j] = '.';
			}
		}

		system("cls"); //clear the console
		init_lvl(arr, &my_snk, &Edge, &length, &flag);
		level = 1;

		while (my_snk.head_x < SIZE && my_snk.head_y < SIZE && my_snk.head_x >= 0 && my_snk.head_y >= 0)
		{
			//redraw the console   
			SetConsoleCursorPosition(hConsole, position);
			write_arr(arr);
			printf("Score: %d.", score);

			//stop movement
			Sleep(difficulty); 

			//handle keypress
			if (_kbhit() != 0)
			{
				press = (char)_getch();
				switch (press)
				{
				case 'w':
					my_snk.wayh_x = -1;
					my_snk.wayh_y = 0;
					break;
				case 'a':
					my_snk.wayh_x = 0;
					my_snk.wayh_y = -1;
					break;
				case 'd':
					my_snk.wayh_x = 0;
					my_snk.wayh_y = 1;
					break;
				case 's':
					my_snk.wayh_x = 1;
					my_snk.wayh_y = 0;
					break;
				case '0':
					printf("\nInput something to start.\nPut 0 to exit.\n");
					press = (char)_getch();
					system("cls");
					break;

				//shot treatment
				case (char)32:
					if (length != 1 && kind == 2)
					{
						num_of_v++;
						length--;
						arr[my_snk.tail_x][my_snk.tail_y] = '.';

						//the movement of the tail, depending on the presence of the snake turn
						if (Edge.start != NULL)
						{
							if ((my_snk.tail_x == Edge.start->addr_x) && (my_snk.tail_y == Edge.start->addr_y))
							{
								my_snk.wayt_x = Edge.start->wt_x;
								my_snk.wayt_y = Edge.start->wt_y;
								DeleteEdge(&Edge);
							}
						}
						my_snk.tail_x += my_snk.wayt_x;
						my_snk.tail_y += my_snk.wayt_y;
						arr[my_snk.tail_x][my_snk.tail_y] = kind_edge(my_snk.wayt_x, my_snk.wayt_y);
						i1 = my_snk.head_x;
						j1 = my_snk.head_y;

						//the creation of the shot and all the checks for him
						num_v = (struct war*)realloc(num_v, num_of_v * sizeof(struct war));
						if (num_v == NULL)
						{
							Free(arr, num_v, &Edge);
						}

						num_v[num_of_v - 1].wayv_x = my_snk.wayh_x;
						num_v[num_of_v - 1].wayv_y = my_snk.wayh_y;
						num_v[num_of_v - 1].coord_x = my_snk.head_x;
						num_v[num_of_v - 1].coord_y = my_snk.head_y;
						i1 = num_v[num_of_v - 1].coord_x;
						j1 = num_v[num_of_v - 1].coord_y;
						tmp_x = num_v[num_of_v - 1].wayv_x;
						tmp_y = num_v[num_of_v - 1].wayv_y;
						if (i1 + tmp_x < SIZE && j1 + tmp_y < SIZE && i1 + tmp_x >= 0 && j1 + tmp_y >= 0)
						{
							if (hit_food(arr, num_of_v - 1, i1, j1, tmp_x, tmp_y, my_snk, num_v) == 1)
								continue;
							arr[i1 + tmp_x][j1 + tmp_y] = 'o';
							num_v[num_of_v - 1].coord_x += tmp_x;
							num_v[num_of_v - 1].coord_y += tmp_y;
						}
					}
				}
				if (press == '0')
					break;

				//if you press a lot of buttons
				while (_kbhit() != 0)
					((char)_getch() != '\n');
				if (Add(&Edge, my_snk.wayh_x, my_snk.wayh_y, my_snk.head_x, my_snk.head_y) == 1)
				{
					Clear(&Edge);
					for (i = 0; i < SIZE; i++)
					{
						free(arr[i]);
					}
					free(arr);
					free(num_v);
				}
			}
			//processing all the existing shots
			if (kind == 2)
			{
				for (i = 0; i < num_of_v; i++)
				{
					if (num_v[i].coord_x != -1 && num_v[i].coord_y != -1)
					{
						i1 = num_v[i].coord_x;
						j1 = num_v[i].coord_y;
						tmp_x = num_v[i].wayv_x;
						tmp_y = num_v[i].wayv_y;
						arr[i1][j1] = '.';
						if (i1 + tmp_x < SIZE && j1 + tmp_y < SIZE && i1 + tmp_x >= 0 && j1 + tmp_y >= 0)
						{
							if (hit_food(arr, i, i1, j1, tmp_x, tmp_y, my_snk, num_v) == 1)
								continue;
						}
						if ((i1 + (tmp_x * 2)) < SIZE && (j1 + (tmp_y * 2)) < SIZE && 
							(i1 + (tmp_x * 2)) >= 0 && (j1 + (tmp_y * 2)) >= 0)
						{
							if (hit_food(arr, i, i1, j1, tmp_x * 2, tmp_y * 2, my_snk, num_v) == 1)
								continue;

							//moving bullet
							if (arr[i1 + tmp_x * 2][j1 + tmp_y * 2] == '.')
							{
								num_v[i].coord_x += tmp_x * 2;
								num_v[i].coord_y += tmp_y * 2;
								i1 = num_v[i].coord_x;
								j1 = num_v[i].coord_y;
								arr[i1][j1] = 'o';
								continue;
							}
						}
						un_init(num_v, i);
					}
				}
			}

			//snake movement
			arr[my_snk.tail_x][my_snk.tail_y] = '.';
			my_snk.head_x += my_snk.wayh_x;
			my_snk.head_y += my_snk.wayh_y;
			if ((my_snk.head_x >= SIZE || my_snk.head_y >= SIZE || my_snk.head_x < 0 ||
				my_snk.head_y < 0) || (arr[my_snk.head_x][my_snk.head_y] != '.' && arr[my_snk.head_x][my_snk.head_y] != '*'))
				break;

			if (eating(arr, &my_snk, &length, &score) == 1)
				break;
			//the movement of the tail, depending on the presence of the snake turn
			if (Edge.start != NULL)
			{
				if ((my_snk.tail_x == Edge.start->addr_x) && (my_snk.tail_y == Edge.start->addr_y))
				{
					my_snk.wayt_x = Edge.start->wt_x;
					my_snk.wayt_y = Edge.start->wt_y;
					DeleteEdge(&Edge);
				}
			}
			my_snk.tail_x += my_snk.wayt_x;
			my_snk.tail_y += my_snk.wayt_y;
			arr[my_snk.head_x][my_snk.head_y] = kind_edge(my_snk.wayh_x, my_snk.wayh_y);
			arr[my_snk.tail_x][my_snk.tail_y] = kind_edge(my_snk.wayt_x, my_snk.wayt_y);
			flag_level = check_level(position, hConsole, &level, arr, &my_snk, &Edge, &length, &flag);
			if (flag_level == 1)
			{
				break;
			}
		}

		Free(arr, num_v, &Edge);
		system("cls");
		if (flag_level == 1)
		{
			puts("Can't open file!");
		}
		if (flag != 1)
			puts("GAME OVER.");
		else
			puts("YOU WIN!!!");
		printf("You length: %d.\nYou level: %d.\nYou score: %d.\n", length, level, score);
		printf("Input ENTER to play again. Input 0 to exit. Input 1 to see help.\n");
		score = 1;
		while ((int)main_flag != 13 && (int)main_flag != 48 && (int)main_flag != 49)
		{ 
			main_flag = _getch();
		}
		if ((int)main_flag == 49)
		{
			write_help();
			while ((int)main_flag != 13 && (int)main_flag != 48)
			{
				main_flag = _getch();
			}
		}
		system("cls");
	}while ((int)main_flag == 13);
	return ;
}