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

void Write(struct ListEdge* list)
{
	puts("\n");
	struct List* temp = list->start;
	while (temp != NULL)
	{
		printf("%d %d\n", temp->wt_x, temp->wt_y);
		temp = temp->next;
	}
}
struct ListEdge* EdgeGive(struct ListEdge* lstp)
{
	return lstp;
}

int kind_edge(int x, int y)
{
	if (x == -1 && y == 0)
		return '^';
	if (x == 0 && y == -1)
		return '<';
	if (x == 0 && y == 1)
		return '>';
	if (x == 1 && y == 0)
		return 'V';
}
void main(void)
{
	struct ListEdge Edge;
	struct ListEdge* EdgeP;
	struct List* ls;
	Init(&Edge);
	int check, n, m, i, j, fi, coordinate_x, coordinate_y, flag, head_x, head_y, way_x, way_y, tail_x, tail_y, wayt_x, wayt_y, length;
	char press;
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
	//выделение памяти
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
	coordinate_x = 0 + rand() % n;
	coordinate_y = 0 + rand() % m;
	arr[coordinate_x][coordinate_y] = '*';

	head_x = 0 + rand() % n;
	head_y = 0 + rand() % m;
	arr[head_x][head_y] = '>';
	tail_x = head_x;
	tail_y = head_y;

	way_x = 0;
	way_y = 1;
	wayt_x = way_x;
	wayt_y = way_y;
	length = 1;
	while (head_x < n && head_y < m && head_x >= 0 && head_y >= 0)
	{
		//вывод
		system("cls");
		printf("  ");
		for (j = 0; j < m; j++)
		{
			printf("%3d", j);
		}
		for (i = 0; i < n; i++)
		{
			printf("\n%2d", i);
			for (j = 0; j < m; j++)
			{
				printf("%3c", arr[i][j]);
			}
		}
		printf("\n");
		
		//поворот
		_sleep(500);
		EdgeP = EdgeGive(&Edge);
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
			//когда много клавиш нажато
			while (kbhit() != 0)
				((char)getch() != '\n');
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
			do
			{
				coordinate_x = 0 + rand() % n;
				coordinate_y = 0 + rand() % m;
			} while (arr[coordinate_x][coordinate_y] != '.');
			arr[coordinate_x][coordinate_y] = '*';
			arr[tail_x][tail_y] = 'o';
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
	printf("You length: %d.\n", length);
	puts("GAME OVER.");
	getch();
	return 0;
}