#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_diagonal(int queens[], int n)
{
	for (int col = 0; col < n; col++)
	{
		for (int col2 = col + 1; col2 < n; col2++)
		{
			if (abs(col2 - col) == abs(queens[col] - queens[col2]))
				return (0);
		}
	}
	return (1);
}

void swap(int queens[], int index, int i)
{
	int temp;
	temp = queens[index];
	queens[index] = queens[i];
	queens[i] = temp;
}

void solve_queens(int queens[], int index, int size)
{
	int i;
	if (index == size - 1)
	{
		if (check_diagonal(queens, size))
		{
			for (int i = 0; i < size; i++)
				printf("%i ", queens[i]);
			printf("\n");
			exit(1);
		}
		return;
	}
	else if (!check_diagonal(queens, index))
		return;
	i = index;
	while (i < size)
	{
		swap(queens, index, i);
		solve_queens(queens, index + 1, size);
		swap(queens, index, i);
		i++;
	}
}

int main(int argc, char **argv)
{
	int n;
	if (argc < 3)
	{
		write(1, "gib numbers\n", 11);
		return 0;
	}

	
	n = atoi(argv[1]);
	int array[n];
	for (int i = 0; i < n; i++)
		array[i] = i;
	solve_queens(array, 0, n);
}