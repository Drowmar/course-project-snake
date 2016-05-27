#define SIZE 15
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
	return;
}