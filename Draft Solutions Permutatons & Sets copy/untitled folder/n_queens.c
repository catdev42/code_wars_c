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
		}
		return;
	}
	// else if (!check_diagonal(queens, index))
	// 	return;
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
	int how_many_queens;
	if (argc < 2)
	{
		write(1, "gib number\n", 11);
		return 0;
	}
	how_many_queens = atoi(argv[1]);
	int array[how_many_queens];
	for (int i = 0; i < how_many_queens; i++)
		array[i] = i;
	solve_queens(array, 0, how_many_queens);
}
