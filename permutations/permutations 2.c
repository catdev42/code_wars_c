#include <stdio.h>
#include <stdlib.h>

void	swap(int *i, int *j);
void	permutations(int *arr, int len);
void	permute_down_to_index(int index, int *arr, int len);
int		*copy_arr(int *dest, int *arr, int len);

void	swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	permutations(int *arr, int len)
{
	int	i;
	int	*temparr;

	// we are going to work with the index.... not the number
	temparr = malloc(len * sizeof(int));
	i = len - 1;
	while (i > 0)
	{
		copy_arr(temparr, arr, len);
		permute_down_to_index(i - 1, temparr, len);
		i--;
	}
}

void	permute_down_to_index(int index, int *arr, int len)
{
	int	i;

	i = len - 1;
	while (i > index)
	{
		swap(&arr[i], &arr[i - 1]);
		for (int j = 0; j < len; j++)
			printf("%i", arr[j]);
		swap(&arr[i], &arr[i - 1]);
		i--;
	}
	printf("\n");
	/*
	01234
	01243
	*/
}

int	*copy_arr(int *dest, int *arr, int len)
{
	for (int i = 0; i < len; i++)
		dest[i] = arr[i];
	return (dest);
}

int	main(void)
{
	int n = 5;
	//    if (scanf("%d",&n) != 1) exit (1);
	int arr[n];
	for (int i = 0; i < n; ++i)
		arr[i] = i + 1;
	permutations(arr, n);
	return (0);
}