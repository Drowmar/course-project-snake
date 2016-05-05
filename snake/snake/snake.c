#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Windows.h"
#include "levels.h"
#include "stack.h"
#include <time.h>
#define MAX_LONG 10
#define SIZE 15
struct var
{
	int wayv_x;
	int wayv_y;
	int coord_x;
	int coord_y;
};

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

void write_arr(char* arr[])
{
	int i, j;
	for (j = 0; j <= SIZE + 1; j++)
	{
		printf("%2c", '%');
	}
	for (i = 0; i < SIZE; i++)
	{
		printf("\n%2c", '%');
		for (j = 0; j < SIZE; j++)
		{
			if (arr[i][j] != '.')
				printf("%2c", arr[i][j]);
			else
				printf("  ");
		}
		printf("%2c", '%');
	}
	printf("\n");
	for (j = 0; j <= SIZE + 1; j++)
	{
		printf("%2c", '%');
	}
	printf("\n"); 
}
void init_lvl(char* arr[], int* head_x, int* head_y, int* tail_x, int* tail_y, int* coordinate_x, int* coordinate_y, int* way_x, int* way_y, int* wayt_x, int* wayt_y, struct ListEdge* Edge, int* length, int* flag)
{
	*head_x = 6;
	*head_y = 1;
	arr[*head_x][*head_y] = '>';
	*tail_x = *head_x;
	*tail_y = *head_y;
	do
	{
		*coordinate_x = 0 + rand() % SIZE;
		*coordinate_y = 0 + rand() % SIZE;
	} while (arr[*coordinate_x][*coordinate_y] != '.');
	arr[*coordinate_x][*coordinate_y] = '*';

	*way_x = 0;
	*way_y = 1;
	*wayt_x = *way_x;
	*wayt_y = *way_y;
	*length = 1;
	*flag = 0;

	Clear(Edge);
	Init(Edge);
	write_arr(arr);
	printf("Input ENTER to start.\n");
	while ((int)_getch() != 13){}
	system("cls");  
}

void Free (char *arr[], struct var *num_v, struct ListEdge *edge)
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

void un_init(struct var* num_v, int i)
{
	num_v[i].coord_x = -1;
	num_v[i].coord_y = -1;
	num_v[i].wayv_x = 0;
	num_v[i].wayv_y = 0;
	return ;
}
void main(void)
{
	struct var* num_v = NULL;
	char** arr = NULL;
	int score = 1, flag_level = 0, kind = 0, wx, wy, num_of_v = 0, i1, j1, level, choice, defficulty, check, i, j, fi, coordinate_x, coordinate_y, flag, head_x, head_y, way_x, way_y, tail_x, tail_y, wayt_x, wayt_y, length;
	char press, main_flag = 0;
	puts("Game snake.\nYou control the snake, but the snake is moving itself.\nYour goal is to eat the food and grow as much as possible.\nYou win when your snake will occupy the entire field.\nControl:\nw - up;\na - right;\nd - left;\ns - down;\nIf you want pause - press 0(number).");
	struct ListEdge Edge;
	Init(&Edge);
	srand((unsigned int)time(NULL));
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 0;
	position.Y = 0;
	do
	{
		main_flag = 0;
		num_of_v = 0;
		num_v = (struct var*)malloc(0 * sizeof(struct var));
		if (num_v == NULL)
		{
			puts("Out if memory.");
			return;
		}

		//выделение памяти
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
				for (fi = 0; fi <= i; fi++)
				{
					free(arr[fi]);
				}
				free(arr);
				return;
			}
		}
		printf("Input difficulty:\n1 - easy;\n2 - medium;\n3 - hard.\n4 - expert.\n");
		do
		{
			check = scanf_s("%d", &choice);
			if (check == 1 && choice != 1 && choice != 2 && choice != 3 && choice != 4)
			{
				flag = 1;
				printf("Incorrect input!\n");
				fflush(stdin);
				continue;
			}
			flag = 0;
			if (getchar() != '\n')
			{
				flag = 1;
				fflush(stdin);
			}
			if (flag == 1 || check != 1)
				printf("Incorrect input!\n");
		} while (check != 1 || flag == 1);
		switch (choice) {
		case 1:
			defficulty = 400;
			break;
		case 2:
			defficulty = 250;
			break;
		case 3:
			defficulty = 100;
			break;
		case 4:
			defficulty = 70;
			break;
		}
		printf("Input kind of game.\n1 - classic.\n2 - modern.\n");
		do
		{
			check = scanf_s("%d", &kind);
			if (check == 1 && kind != 1 && kind != 2)
			{
				flag = 1;
				printf("Incorrect input!\n");
				fflush(stdin);
				continue;
			}
			flag = 0;
			if (getchar() != '\n')
			{
				flag = 1;
				fflush(stdin);
			}
			if (flag == 1 || check != 1)
				printf("Incorrect input!\n");
		} while (check != 1 || flag == 1);
		if (kind == 2)
		{
			system("cls");
			puts("You can shoot pressing the space.");
			Sleep(2000);
		}
		//инициализация
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				arr[i][j] = '.';
			}
		}
		system("cls");
		init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
		level = 1;

		while (head_x < SIZE && head_y < SIZE && head_x >= 0 && head_y >= 0)
		{
			//вывод
			//system("cls");        
			SetConsoleCursorPosition(hConsole, position);
			write_arr(arr);
			printf("Score: %d.", score);

			//поворот
			Sleep(defficulty);
			if (_kbhit() != 0)
			{
				press = (char)_getch();
				switch (press)
				{
				case 'w':
					way_x = -1;
					way_y = 0;
					break;
				case 'a':
					way_x = 0;
					way_y = -1;
					break;
				case 'd':
					way_x = 0;
					way_y = 1;
					break;
				case 's':
					way_x = 1;
					way_y = 0;
					break;
				case '0':
					printf("Input something to start.\n");
					_getch();
					system("cls");
					break;
				case (char)32:
					if (length != 1 && kind == 2)
					{
						num_of_v++;
						length--;
						arr[tail_x][tail_y] = '.';
						if (Edge.start != NULL)
						{
							if ((tail_x == Edge.start->addr_x) && (tail_y == Edge.start->addr_y))
							{
								wayt_x = Edge.start->wt_x;
								wayt_y = Edge.start->wt_y;
								DeleteEdge(&Edge);
							}
						}
						tail_x += wayt_x;
						tail_y += wayt_y;
						arr[tail_x][tail_y] = kind_edge(wayt_x, wayt_y);
						i1 = head_x;
						j1 = head_y;
						num_v = (struct var*)realloc(num_v, num_of_v * sizeof(struct var));
						if (num_v == NULL)
						{
							Free(arr, num_v, &Edge);
						}
						num_v[num_of_v - 1].wayv_x = way_x;
						num_v[num_of_v - 1].wayv_y = way_y;
						num_v[num_of_v - 1].coord_x = head_x;
						num_v[num_of_v - 1].coord_y = head_y;
						i1 = num_v[num_of_v - 1].coord_x;
						j1 = num_v[num_of_v - 1].coord_y;
						wx = num_v[i].wayv_x;
						wy = num_v[i].wayv_y;
						if (i1 + wx < SIZE && j1 + wy < SIZE && i1 + wx >= 0 && j1 + wy >= 0)
						{
							if (arr[i1 + wx][j1 + wy] == '*')
							{
								arr[i1 + wx][j1 + wy] = '.';
								un_init(num_v, i);
								do
								{
									coordinate_x = 0 + rand() % SIZE;
									coordinate_y = 0 + rand() % SIZE;
								} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == tail_x && coordinate_y == tail_y));
								arr[coordinate_x][coordinate_y] = '*';
								continue;
							}
							arr[i1 + wx][j1 + wy] = 'o';
							num_v[num_of_v - 1].coord_x += wx;
							num_v[num_of_v - 1].coord_y += wy;
						}
					}
				}
				//когда много клавиш нажато
				while (_kbhit() != 0)
					((char)_getch() != '\n');
				if (Add(&Edge, way_x, way_y, head_x, head_y) == 1)
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
			if (kind == 2)
			{
				for (i = 0; i < num_of_v; i++)
				{
					if (num_v[i].coord_x != -1 && num_v[i].coord_y != -1)
					{
						i1 = num_v[i].coord_x;
						j1 = num_v[i].coord_y;
						wx = num_v[i].wayv_x;
						wy = num_v[i].wayv_y;
						arr[i1][j1] = '.';
						if (i1 + wx < SIZE && j1 + wy < SIZE && i1 + wx >= 0 && j1 + wy >= 0)
						{
							if (arr[i1 + wx][j1 + wy] == '%')
							{
								arr[i1 + wx][j1 + wy] = '.';
								un_init(num_v, i);
								continue;
							}
							if (arr[i1 + wx][j1 + wy] == '*')
							{
								arr[i1 + wx][j1 + wy] = '.';
								un_init(num_v, i);
								do
								{
									coordinate_x = 0 + rand() % SIZE;
									coordinate_y = 0 + rand() % SIZE;
								} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == tail_x && coordinate_y == tail_y));
								arr[coordinate_x][coordinate_y] = '*';
								continue;
							}
							if (arr[i1 + wx][j1 + wy] != '.')
							{
								un_init(num_v, i);
								continue;
							}
						}
						if ((i1 + (wx * 2)) < SIZE && (j1 + (wy * 2)) < SIZE && (i1 + (wx * 2)) >= 0 && (j1 + (wy * 2)) >= 0)
						{
							if (arr[i1 + wx * 2][j1 + wy * 2] == '*')
							{
								arr[i1 + wx * 2][j1 + wy * 2] = '.';
								un_init(num_v, i);
								do
								{
									coordinate_x = 0 + rand() % SIZE;
									coordinate_y = 0 + rand() % SIZE;
								} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == tail_x && coordinate_y == tail_y));
								arr[coordinate_x][coordinate_y] = '*';
								continue;
							}
							if (arr[i1 + wx * 2][j1 + wy * 2] == '%')
							{
								arr[i1 + wx * 2][j1 + wy * 2] = '.';
								un_init(num_v, i);
								continue;
							}
							if (arr[i1 + wx * 2][j1 + wy * 2] != '.')
							{
								un_init(num_v, i);
								continue;
							}
							if (arr[i1 + wx * 2][j1 + wy * 2] == '.')
							{
								num_v[i].coord_x += wx * 2;
								num_v[i].coord_y += wy * 2;
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
			arr[tail_x][tail_y] = '.';
			//встреча с едой
			head_x += way_x;
			head_y += way_y;
			if ((head_x >= SIZE || head_y >= SIZE || head_x < 0 || head_y < 0) || (arr[head_x][head_y] != '.' && arr[head_x][head_y] != '*'))
				break;
			if (arr[head_x][head_y] == '*')
			{
				if (length + 1 == SIZE * SIZE)
				{
					flag = 1;
					length++; 
					score++;
					break;
				}
				do
				{
					coordinate_x = 0 + rand() % SIZE;
					coordinate_y = 0 + rand() % SIZE;
				} while (arr[coordinate_x][coordinate_y] != '.');
				arr[coordinate_x][coordinate_y] = '*';
				tail_x -= wayt_x;
				tail_y -= wayt_y;
				length++;
				score++;
			}
			if (Edge.start != NULL)
			{
				if ((tail_x == Edge.start->addr_x) && (tail_y == Edge.start->addr_y))
				{
					wayt_x = Edge.start->wt_x;
					wayt_y = Edge.start->wt_y;
					DeleteEdge(&Edge);
				}
			}
			tail_x += wayt_x;
			tail_y += wayt_y;
			arr[head_x][head_y] = kind_edge(way_x, way_y);
			arr[tail_x][tail_y] = kind_edge(wayt_x, wayt_y);
			if (length == MAX_LONG)
			{
				flag_level = 0;
				switch (level)
				{
				case 1:
					if (lvl_2(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 2;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				case 2:
					if (lvl_3(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 3;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				case 3:
					if (lvl_4(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 4;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				case 4:
					if (lvl_5(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 5;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				case 5:
					if (lvl_6(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 6;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				case 6:
					if (lvl_7(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 7;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				case 7:
					if (lvl_8(arr) == 1)
					{
						flag_level = 1;
						break;
					}
					level = 8;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
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
					level = 9;
					SetConsoleCursorPosition(hConsole, position);
					init_lvl(arr, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag);
					break;
				}
				if (flag_level == 1)
				{
					break;
				}
			}
		}
		i = i;
		//освобождение памяти
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
		printf("You length: %d.\nYou level: %d.\n", length, level);
		printf("Input ENTER to play again. Put 0 to exit.\n");
		score = 1;
		while ((int)main_flag != 13 && (int)main_flag != 48)
		{ 
			main_flag = _getch();
		}
		system("cls");
	}while ((int)main_flag == 13);
	return ;
}