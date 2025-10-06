#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int end, int start)
{
	int size;

	size = 0;
	size = (end - start);
	if (size < 0)
		size = size * -1;
	return (size);
}

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = ft_abs(end, start) + 1; // fixed
	res = malloc(size * sizeof(int)); // fixed a few times
	if (!res)
		return (NULL);
	i = 0;
	if (start < end) //fixed
	{
		while (start <= end)
		{
			res[i] = start;
			start += 1;
			i += 1;
		}
	}
	else
	{
		while (start >= end) 
		{
			res[i] = start;
			start -= 1;
			i += 1;
		}
	}
	return (res);
}

/*
Main
Not part of assignment : just for testing
*/
int *ft_range(int start, int end);

int main(int argc, char **argv)
{
	(void)argc;
	int	arr_len;
	int	*arr;

	arr_len = abs(atoi(argv[2]) - atoi(argv[1]));
	arr = ft_range(atoi(argv[1]), atoi(argv[2]));
	for (int i = 0; i <= arr_len; i += 1)
		printf("%d\n", arr[i]);
	free(arr);
	return (EXIT_SUCCESS);
}
