#include <stdio.h>
#define SIZE 15
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