#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	int check, n, m, i, j, fi, coordinate_x, coordinate_y, player, number, flag;
	srand(time(NULL));
	char** arr = NULL;
	//проверка на ввод
	printf("Input size.\n");
	do
	{
		check = scanf("%d%d", &n, &m);
		flag = 0;
		if (getchar() != '\n')
		{
			flag = 1;
			fflush(stdin);
		}
		if (flag == 1 || check != 2)
			printf("Incorrect input!\n");
	} while (check != 2 || flag == 1);
	//выделение пам€ти
	arr = (char**)malloc(n * sizeof(char*));
	if (arr == NULL)
	{
		printf("ERROR");
		free(arr);
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = NULL;
		arr[i] = (char*)malloc(m * sizeof(char));
		if (arr[i] == NULL)
		{
			printf("ERROR");
			for (fi = 0; fi <= i; fi++)
			{
				free(arr[fi]);
			}
			free(arr);
			return 0;
		}
	}
	//инициализаци€
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			arr[i][j] = '.';
		}
	}
	system("cls");

	//генераци€ еды
	coordinate_x = 0 + rand() % n;
	coordinate_y = 0 + rand() % m;
	arr[coordinate_x][coordinate_y] = '*';

	//вывод
	printf("  ");
	for (j = 1; j <= m; j++)
	{
		printf("%3d", j);
	}
	for (i = 0; i < n; i++)
	{
		printf("\n%2d", i + 1);
		for (j = 0; j < m; j++)
		{
			printf("%3c", arr[i][j]);
		}
	}
	printf("\n");
	//освобождение пам€ти
	for (i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);

	getch();
	return 0;
}