#include <stdbool.h>
#include <stdio.h>
#include <string.h>

swap 

sort

void	permute(char *str, int index, int len)
{
	int i;

	if (index == len - 1)
	{
		puts(str); // this is printf
		return ;
	}
	i = index; //0
	while (i < len)
	{
		swap(&str[index], &str[i]);

		char strnew[len + 1];
		for (int j = 0; str[i]; j++)
			strnew[j] = str[j];
		strnew[len] = 0;
		ft_sort(&strnew[index+1]);

		permute(strnew, index + 1, len);
		
		swap(&str[index], &str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	sort(argv[1]);
	premute(argv[1], 0, ft_strlen(argv[1]));
}
