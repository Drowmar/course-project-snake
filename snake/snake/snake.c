#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#define MAX_LONG 10
void lvl_2(char* arr[], int n, int m);
void lvl_3(char* arr[], int n, int m);
void lvl_4(char* arr[], int n, int m);
void lvl_5(char* arr[], int n, int m);
void lvl_6(char* arr[], int n, int m);
void lvl_7(char* arr[], int n, int m);
void lvl_8(char* arr[], int n, int m);


struct var
{
	int wayv_x;
	int wayv_y;
	int coord_x;
	int coord_y;
};
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

int Add(struct ListEdge* lstp, int x, int y, int a_x, int a_y)
{
	struct List* temp = (struct List*)malloc(sizeof(struct List));
	if (temp == NULL)
	{
		return 1;
	}

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
	return 0;
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
void init_lvl(char* arr[], int n, int m, int* head_x, int* head_y, int* tail_x, int* tail_y, int* coordinate_x, int* coordinate_y, int* way_x, int* way_y, int* wayt_x, int* wayt_y, struct ListEdge* Edge, int* length, int* flag)
{
	*head_x = 6;
	*head_y = 1;
	arr[*head_x][*head_y] = '>';
	*tail_x = *head_x;
	*tail_y = *head_y;
	do
	{
		*coordinate_x = 0 + rand() % n;
		*coordinate_y = 0 + rand() % m;
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
	write_arr(arr, n, m);
	printf("Input ENTER to start.\n");
	while ((int)_getch() != 13){}
	system("cls");  
}

void main(void)
{
	struct var* num_v = NULL;
	num_v = (struct var*)malloc(0 * sizeof(struct var));
	if (num_v == NULL)
	{
		puts("Out if memory.");
		return;
	}
	puts("Game snake.\nYou control the snake, but the snake is moving itself.\nYour goal is to eat the food and grow as much as possible.\nYou win when your snake will occupy the entire field.\nControl:\nw - up;\na - right;\nd - left;\ns - down;\nIf you want pause - press 0(number).");
	struct ListEdge Edge;
	Init(&Edge);
	int kind = 0, wx, wy, num_of_v = 0, i1, j1, level, choice, defficulty, check, n, m, i, j, fi, coordinate_x, coordinate_y, flag, head_x, head_y, way_x, way_y, tail_x, tail_y, wayt_x, wayt_y, length, stime;
	char press;
	long ltime;
	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);
	char** arr = NULL;

	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 0;
	position.Y = 0;

	n = 15;
	m = 15;
	//��������� ������
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
		defficulty = 70;
		break;
	}
	printf("Input kind of game.\n1 - classic.\n2 - modern.\n");
	do
	{
		check = scanf("%d", &kind);
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
	 
	//�������������
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			arr[i][j] = '.';
		}
	}
	system("cls");
	init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
	level = 1;

	while (head_x < n && head_y < m && head_x >= 0 && head_y >= 0)
	{
		//�����
		//system("cls");        
		SetConsoleCursorPosition(hConsole, position);
		write_arr(arr, n, m);
		
		//�������
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
					num_v[num_of_v - 1].wayv_x = way_x;
					num_v[num_of_v - 1].wayv_y = way_y;
					num_v[num_of_v - 1].coord_x = head_x;
					num_v[num_of_v - 1].coord_y = head_y;
					i1 = num_v[num_of_v - 1].coord_x;
					j1 = num_v[num_of_v - 1].coord_y;
					wx = num_v[i].wayv_x;
					wy = num_v[i].wayv_y;
					if (i1 + wx < n && j1 + wy < m && i1 + wx >= 0 && j1 + wy >= 0)
					{
						if (arr[i1 + wx][j1 + wy] == '*')
						{
							arr[i1 + wx][j1 + wy] = '.';
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
							do
							{
								coordinate_x = 0 + rand() % n;
								coordinate_y = 0 + rand() % m;
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
			//����� ����� ������ ������
			while (_kbhit() != 0)
				((char)_getch() != '\n');
			if (Add(&Edge, way_x, way_y, head_x, head_y) == 1)
			{
				Clear(&Edge); 
				for (i = 0; i < n; i++)
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
					if (i1 + wx < n && j1 + wy < m && i1 + wx >= 0 && j1 + wy >= 0)
					{
						if (arr[i1 + wx][j1 + wy] == '%')
						{
							arr[i1 + wx][j1 + wy] = '.';
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
							continue;
						}
						if (arr[i1 + wx][j1 + wy] == '*')
						{
							arr[i1 + wx][j1 + wy] = '.';
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
							do
							{
								coordinate_x = 0 + rand() % n;
								coordinate_y = 0 + rand() % m;
							} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == tail_x && coordinate_y == tail_y));
							arr[coordinate_x][coordinate_y] = '*';
							continue;
						}
						if (arr[i1 + wx][j1 + wy] != '.')
						{
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
							continue;
						}
					}
					if ((i1 + (wx * 2)) < n && (j1 + (wy * 2)) < m && (i1 + (wx * 2)) >= 0 && (j1 + (wy * 2)) >= 0)
					{
						if (arr[i1 + wx * 2][j1 + wy * 2] == '*')
						{
							arr[i1 + wx * 2][j1 + wy * 2] = '.';
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
							do
							{
								coordinate_x = 0 + rand() % n;
								coordinate_y = 0 + rand() % m;
							} while (arr[coordinate_x][coordinate_y] != '.' || (coordinate_x == tail_x && coordinate_y == tail_y));
							arr[coordinate_x][coordinate_y] = '*';
							continue;
						}
						if (arr[i1 + wx * 2][j1 + wy * 2] == '%')
						{
							arr[i1 + wx * 2][j1 + wy * 2] = '.';
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
							continue;
						}
						if (arr[i1 + wx * 2][j1 + wy * 2] != '.')
						{
							num_v[i].coord_x = -1;
							num_v[i].coord_y = -1;
							num_v[i].wayv_x = 0;
							num_v[i].wayv_y = 0;
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
					num_v[i].coord_x = -1;
					num_v[i].coord_y = -1;
					num_v[i].wayv_x = 0;
					num_v[i].wayv_y = 0;
				}
			}
		}
		arr[tail_x][tail_y] = '.';
		//������� � ����
		head_x += way_x;
		head_y += way_y;
		if ((head_x >= n || head_y >= m || head_x < 0 || head_y < 0) || (arr[head_x][head_y] != '.' && arr[head_x][head_y] != '*'))
			break;
		if (arr[head_x][head_y] == '*')
		{
			if (length + 1 == n * m)
			{
				flag = 1;
				length++;
				break;
			}
			do
			{
				coordinate_x = 0 + rand() % n;
				coordinate_y = 0 + rand() % m;
			} while (arr[coordinate_x][coordinate_y] != '.');
			arr[coordinate_x][coordinate_y] = '*';
			tail_x -= wayt_x;
			tail_y -= wayt_y;
			length++;
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
		if (length == MAX_LONG && level == 1)
		{
			lvl_2(arr, n, m);
			level = 2;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 2)
		{
			lvl_3(arr, n, m);
			level = 3;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 3)
		{
			lvl_4(arr, n, m);
			level = 4;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 4)
		{
			lvl_5(arr, n, m);
			level = 5;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 5)
		{
			lvl_6(arr, n, m);
			level = 6;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 6)
		{
			lvl_7(arr, n, m);
			level = 7;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 7)
		{
			lvl_8(arr, n, m);
			level = 8;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
		if (length == MAX_LONG && level == 8)
		{
			i = 0;
			j = 0;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					arr[i][j] = '.';
				}
			}
			level = 9;
			SetConsoleCursorPosition(hConsole, position);
			init_lvl(arr, n, m, &head_x, &head_y, &tail_x, &tail_y, &coordinate_x, &coordinate_y, &way_x, &way_y, &wayt_x, &wayt_y, &Edge, &length, &flag, &level);
		}
	}
	//������������ ������
	for (i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(num_v);
	Clear(&Edge);
	system("cls");
	if (flag != 1)
		puts("GAME OVER.");
	else
		puts("YOU WIN!!!");
	printf("You length: %d.\nYou level: %d.\n", length, level);

	printf("Input ENTER to end.\n");
	while ((int)_getch() != 13){}
	return ;
}
