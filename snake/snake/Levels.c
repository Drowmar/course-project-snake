#include <stdio.h>
#include "stack.h"
#include "writeArr.h"
#include "Windows.h"
#include <conio.h>
#define SIZE 15

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
	return;
}

int lvl_2(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level2.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}
int lvl_3(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level3.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}
int lvl_4(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level4.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}
int lvl_5(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level5.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}
int lvl_6(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level6.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}
int lvl_7(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level7.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}
int lvl_8(char* arr[])
{
	int i, j;
	FILE *f1;
	char ch = ' ';
	if ((f1 = fopen("level8.txt", "r")) == NULL)
	{
		puts("Can't open file.");
		return 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			(void)fscanf_s(f1, "%c", &ch);
			arr[i][j] = ch;
		}
		(void)fscanf_s(f1, "%c", &ch);
	}
	fclose(f1);
	return 0;
}