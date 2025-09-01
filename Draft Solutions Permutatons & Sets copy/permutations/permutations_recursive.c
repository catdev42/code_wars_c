#include <stdio.h>
#include <string.h>

//NOT IN LEXIGRAPHICAL ORDER, WORLS FOR N QUEENS and TSP

// Function to swap two characters
void	swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// Recursive function to generate all permutations
void	generatePermutations(char *str, int start, int len)
{
	if (start == len-1)
	{
		printf("%s\n", str);
	}
	else
	{
		for (int i = start; i < len; i++)
		{
			// Swap  start index with the current index (itself included)
			swap(&str[start], &str[i]);
			generatePermutations(str, start + 1, len);
			// Undo the swap to start the next branch
			swap(&str[start], &str[i]);
		}
	}
}

int	main(int argc, char **argv)
{
	char	input[100] = "012345";
	int		n;

	n = strlen(input);
	printf("Permutations of %s:\n", input);
	generatePermutations(input, 0, n);
	return (0);
}
