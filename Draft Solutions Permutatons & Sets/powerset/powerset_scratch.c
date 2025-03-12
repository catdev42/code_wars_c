// find_subsets(int target, int *numbers, int *current, int make_size, int index, int len)
// {
// 	// include
// 	find_subsets(target, numbers, current, 0, index++, len)
// }

void find_subsets(int numbers[], int ind, int len, int *current, int target)
{
	(if )
	current[ind] = numbers[ind];
	find_subsets(numbers, ind + 1, len, current, target);
}

void push(char **array, char *current_push, int len)
{
	int i = 0;
	while (array[i] && i < (1 << len))
		i++;
	if (i < (1 << len))
		array[i] = current_push;
	return;
}

void free_array(char **array, int len)
{
	int i = 0;
	if (!array)
		exit(1);
	while (array[i] && i < (1 << len))
	{
		free(array[i]);
		i++;
	}
	free(array);
	return;
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		return 1;
	}

	int target = atoi(argv[1]);
	int len = argc - 2;

	// Allocate arrays
	int *numbers = malloc(sizeof(int) * len);
	int **array = malloc(sizeof(int) * (1 << len));
	if (!numbers || !array)
	{
		if (numbers)
			free(numbers);
		if (array)
			free(array);
		return 1;
	}
	int i = 0;
	while (i < (1 << len))
	{
		array[i] = malloc(sizeof(int) * len);
		if (!array[i])
		{
			free_array(array, len);
			exit(1);
		}
		i++;
	}

	// Parse input numbers
	for (int i = 0; i < len; i++)
	{
		numbers[i] = atoi(argv[i + 2]);
	}

	// Find all subsets
	find_subsets(numbers, 0, len, current, target);

	// Clean up
	free(numbers);
	free(current);
	return 0;
}