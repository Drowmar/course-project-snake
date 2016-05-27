#include <stdio.h>
int read()
{
	int check, flag, num;
	do
	{
		check = scanf_s("%d", &num);
		if (check != 1)
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
	return num;
}