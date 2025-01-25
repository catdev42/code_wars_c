#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

// 8,4,5,6,3
// target == 12

printarr(int *curr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%s\n", curr[i]);
	}
}

void	powerset(int *str, int target, int *curr, int index, int sum)
{
	if (sum == target)
}