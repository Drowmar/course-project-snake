//range of complexity
int complexity()
{
	int choice, difficulty;
	printf("Input difficulty:\n1 - easy;\n2 - medium;\n3 - hard.\n4 - expert.\n");
	do
	{
		choice = read();
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);
	if (choice == 0)
		return 1;
	switch (choice) {
	case 1:
		difficulty = 400;
		break;
	case 2:
		difficulty = 250;
		break;
	case 3:
		difficulty = 100;
		break;
	case 4:
		difficulty = 70;
		break;
	}
	return difficulty;
}