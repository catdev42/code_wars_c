#include <stdio.h>
#include <string.h>

// Function to swap two characters
void	swap(char *x, char *y)
{
	char	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

// Recursive function to generate all permutations
void	generatePermutations(char *str, int start, int end)
{
	if (start == end)
	{
		printf("%s\n", str);
	}
	else
	{
		for (int i = start; i <= end; i++)
		{
			// Swap current index with the start index
			swap(&str[start], &str[i]);
			// Recurse for the rest of the string
			generatePermutations(str, start + 1, end);
			// Backtrack to undo the swap
			swap(&str[start], &str[i]);
		}
	}
}

int	main(int argc, char **argv)
{
	char	input[100] = "012345";
	// char	*input;
	int		n;

	// printf("Enter a string to generate permutations: ");
	// scanf("%s", input);
	// input = argv[1];
	n = strlen(input);
	printf("Permutations of %s:\n", input);
	generatePermutations(input, 0, n - 1);
	return (0);
}
