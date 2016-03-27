#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


void main(void)
{
	int check, n, m, i, j, fi, coordinate_x, coordinate_y, player, number, flag, head_x, head_y, way_x, way_y;
	char press;
	srand(time(NULL));
	char** arr = NULL;
	//�������� �� ����
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
	//��������� ������
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
	//�������������
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			arr[i][j] = '.';
		}
	}
	system("cls");

	//��������� ���
	coordinate_x = 0 + rand() % n;
	coordinate_y = 0 + rand() % m;
	arr[coordinate_x][coordinate_y] = '*';

	//�����
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

	head_x = 0 + rand() % n;
	head_y = 0 + rand() % m;
	arr[head_x][head_y] = 'o';

	way_x = 0;
	way_y = 1;
	while (head_x < n && head_y < m && head_x >= 0 && head_y >= 0)
	{
		//�����
		system("cls");
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
		
		//�������
		_sleep(1000); 
		if (kbhit() != 0)
		{
			press = (char)getch();
			if (press == 'w')
			{
				way_x = -1;
				way_y = 0;
			}
			if (press == 'a')
			{
				way_x = 0;
				way_y = -1;
			}
			if (press == 'd')
			{
				way_x = 0;
				way_y = 1;
			}
			if (press == 's')
			{
				way_x = 1;
				way_y = 0;
			}
		}
		arr[head_x][head_y] = '.';
		//������� � ����
		head_x = head_x + way_x;
		head_y = head_y + way_y;
		if (head_y >= m)
			break;
		if (arr[head_x][head_y] == '*')
		{
			coordinate_x = 0 + rand() % n;
			coordinate_y = 0 + rand() % m;
			arr[coordinate_x][coordinate_y] = '*';
		}
		arr[head_x][head_y] = 'o';
	}
	//������������ ������
	for (i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}