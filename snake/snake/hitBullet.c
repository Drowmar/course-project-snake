#include "Windows.h"
#include <time.h>
#include "snake.h"
#define SIZE 15

//disappearance of the bullet
void un_init(struct war* num_v, int i)
{
	num_v[i].coord_x = -1;
	num_v[i].coord_y = -1;
	num_v[i].wayv_x = 0;
	num_v[i].wayv_y = 0;
	return;
}

//hit the food
int hit_food(char *arr[], int i, int i1, int j1, int tmp_x, int tmp_y, struct snake my_snk, struct war* num_v)
{
	srand((unsigned int)time(NULL));
	int coordinate_x, coordinate_y;
	if (arr[i1 + tmp_x][j1 + tmp_y] == '*')
	{
		arr[i1 + tmp_x][j1 + tmp_y] = '.';
		un_init(num_v, i);
		do
		{
			coordinate_x = 0 + rand() % SIZE;
			coordinate_y = 0 + rand() % SIZE;
		} while (arr[coordinate_x][coordinate_y] != '.' ||
			(coordinate_x == my_snk.tail_x && coordinate_y == my_snk.tail_y));
		arr[coordinate_x][coordinate_y] = '*';
		return 1;
	}

	//hit the wall
	if (arr[i1 + tmp_x][j1 + tmp_y] == '%')
	{
		arr[i1 + tmp_x][j1 + tmp_y] = '.';
		un_init(num_v, i);
		return 1;
	}

	//hit the snake
	if (arr[i1 + tmp_x][j1 + tmp_y] != '.')
	{
		un_init(num_v, i);
		return 1;
	}
	return 0;
}