#include <stdio.h>
#include <stdlib.h>

// int n;
void	ft_swap(int i, int ind, int *arr)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[ind];
	arr[ind] = temp;
}

void	print_array(int *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", str[i]);
		i++;
	}
	printf("\n");
}

int	checker(int *arr, int n)
{
	// int num;
	for (int col1 = 0; col1 < n; col1++)
	{
		for (int col2 = col1 + 1; col2 < n; col2++)
		{
		
			if (abs(col2 - col1) == abs(arr[col2] - arr[col1]))
				return (0);
		}
	}
	return (1);
}

int	ft_check_prev(int *arr, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (arr[i] - row == i - col)
			return (0);
		if (arr[i] - row == (i - col) * (-1))
			return (0);
		i++;
	}
	return (1);
}

int	checker_2(int *arr, int n)
{
	int	last_col;
	int	last_row;

	while (n > 0)
	{
		last_col = arr[n - 1];
		last_row = n - 1;
		if (ft_check_prev(arr, last_col, last_row) == 0)
			return (0);
		n--;
	}
	return (1);
}

void	solve(int *str, int ind, int n)
{
	int	i;

	if (ind == n - 1)
	{
		if (checker(str, n))
			print_array(str, n);
		return ;
	}
	i = ind;
	while (i < n)
	{
		ft_swap(i, ind, str);
		solve(str, ind + 1, n);
		ft_swap(i, ind, str);
		i++;
	}
}
int	main(int argc, char **argv)
{
	int i = 0;
	int n;
	if (argc < 2)
		return (0);

	n = atoi(argv[1]);
	int str[n];
	while (i < n)
	{
		str[i] = i;
		i++;
	}
	solve(str, 0, n);
	return (0);
}