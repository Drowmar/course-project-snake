#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct List
{
	int wt_x;
	int wt_y;
	int addr_x;
	int addr_y;
	struct List*next;
};

struct ListEdge
{
	struct List*start;
	struct List*end;
};

void Init(struct ListEdge * lstp)
{
	lstp->start = NULL;
	lstp->end = NULL;
}

void Add(struct ListEdge* lstp, int x, int y, int a_x, int a_y)
{
	struct List* temp = (struct List*)malloc(sizeof(struct List));

	temp->next = NULL;
	temp->wt_x = x;
	temp->wt_y = y;
	temp->addr_x = a_x;
	temp->addr_y = a_y;

	if (lstp->start == NULL)
	{
		lstp->start = temp;
	}
	else
	{
		lstp->end->next = temp;
	}

	lstp->end = temp;
}

void DeleteEdge(struct ListEdge* lstp)
{
	struct List* del = lstp->start;
	lstp->start = lstp->start->next;
	if (lstp->start == NULL)
		lstp->end = NULL;
	free(del);
}

void Clear(struct ListEdge* list)
{
	struct List* del = list->start;
	struct List* temp;
	while (del != NULL)
	{
		temp = del;
		del = del->next;
		free(temp);
	}

	list->start = NULL;
	list->end = NULL;
}

struct ListEdge* EdgeGive(struct ListEdge* lstp)
{
	return lstp;
}

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

void write_arr(char* arr[], int n, int m)
{
	int i, j;
	for (j = 0; j <= m + 1; j++)
	{
		printf("%2c", '%');
	}
	for (i = 0; i < n; i++)
	{
		printf("\n%2c", '%');
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] != '.')
				printf("%2c", arr[i][j]);
			else
				printf("  ");
		}
		printf("%2c", '%');
	}
	printf("\n");
	for (j = 0; j <= m + 1; j++)
	{
		printf("%2c", '%');
	}
	printf("\n");
}
void main(void)
{
	puts("Game snake.\nYou control the snake, but the snake is moving itself.\nYour goal is to eat the food and grow as much as possible.\nYou win when your snake will occupy the entire field.\nControl:\nw - up;\na - right;\nd - left;\ns - down;\nIf you want pause - press 0(number).");
	struct ListEdge Edge;
	struct ListEdge* EdgeP;
	Init(&Edge);
	int choice, defficulty, check, n, m, i, j, fi, coordinate_x, coordinate_y, flag, head_x, head_y, way_x, way_y, tail_x, tail_y, wayt_x, wayt_y, length, stime;
	char press;
	long ltime;
	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);
	char** arr = NULL;
	//проверка на ввод
	printf("Input size. Max lines 23. Max columns 25.\n");
	do
	{
		check = scanf("%d%d", &n, &m);
		if (check == 2 && (n > 23 || m > 25 || n <= 1 || m <= 1))
		{
			flag = 1;
			printf("Incorrect input!\n");
			continue;
		}
		flag = 0;
		if (getchar() != '\n')
		{
			flag = 1;
			fflush(stdin);
		}
		if (flag == 1 || check != 2)
			printf("Incorrect input!\n");
	} while (check != 2 || flag == 1 );
	//выделение памяти
	arr = (char**)malloc(n * sizeof(char*));
	if (arr == NULL)
	{
		printf("ERROR");
		free(arr);
		return ;
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
			return ;
		}
	}
	printf("Input difficulty:\n1 - easy;\n2 - medium;\n3 - hard.\n4 - expert.\n"); 
	do
	{
		check = scanf("%d", &choice);
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
		defficulty = 80;
		break;
	}
	//инициализация
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			arr[i][j] = '.';
		}
	}
	system("cls");

	//генерация еды
	head_x = (0 + rand() % n)/2;
	head_y = (0 + rand() % m)/2;
	arr[head_x][head_y] = '>';
	tail_x = head_x;
	tail_y = head_y;
	do
	{
		coordinate_x = 0 + rand() % n;
		coordinate_y = 0 + rand() % m;
	} while (arr[coordinate_x][coordinate_y] != '.');
	arr[coordinate_x][coordinate_y] = '*';

	way_x = 0;
	way_y = 1;
	wayt_x = way_x;
	wayt_y = way_y;
	length = 1;
	flag = 0;

	write_arr(arr, n, m);
	printf("Input something to start.\n"); 
	_getch();
	while (head_x < n && head_y < m && head_x >= 0 && head_y >= 0)
	{
		//вывод
		system("cls");
		write_arr(arr, n, m);
		
		//поворот
		Sleep(defficulty);
		EdgeP = EdgeGive(&Edge);
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
				break;
			}
			//когда много клавиш нажато
			while (_kbhit() != 0)
				((char)_getch() != '\n');
			Add(&Edge, way_x, way_y, head_x, head_y);
		}
		arr[tail_x][tail_y] = '.';
		//встреча с едой
		head_x = head_x + way_x;
		head_y = head_y + way_y;
		if ((head_x >= n || head_y >= m || head_x < 0 || head_y < 0) || (arr[head_x][head_y] != '.' && arr[head_x][head_y] != '*'))
			break;
		if (arr[head_x][head_y] == '*')
		{
			if (length + 1 == n * m)
			{
				flag = 1;
				length = length + 1;
				break;
			}
			do
			{
				coordinate_x = 0 + rand() % n;
				coordinate_y = 0 + rand() % m;
			} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == tail_x && coordinate_y == tail_y));
			arr[coordinate_x][coordinate_y] = '*';
			tail_x = tail_x - wayt_x;
			tail_y = tail_y - wayt_y;
			length = length + 1;
		}
		if (EdgeP->start != NULL)
		{
			if ((tail_x == EdgeP->start->addr_x) && (tail_y == EdgeP->start->addr_y))
			{
				wayt_x = EdgeP->start->wt_x;
				wayt_y = EdgeP->start->wt_y; 
				DeleteEdge(&Edge);
			}
		}
		tail_x = tail_x + wayt_x;
		tail_y = tail_y + wayt_y;
		arr[head_x][head_y] = kind_edge(way_x, way_y);
		arr[tail_x][tail_y] = kind_edge(wayt_x, wayt_y);
	}
	//освобождение памяти
	for (i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
	Clear(&Edge);
	system("cls");
	if (flag != 1)
		puts("GAME OVER.");
	else
		puts("YOU WIN!!!");
	printf("You length: %d.\n", length);

	_getch();
	Sleep(600);
	_getch();
	return ;
}