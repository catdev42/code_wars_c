#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int							g_len_solution = 0;

typedef struct s_solution_node
{
	char					*str;
	struct s_solution_node	*next;
}							t_node;

int	fint_solution_len(char *str, char *current, int solution_len)
{
	if (balanced(current))
	{
		if (strlen(current) > g_len_solution)
			g_len_solution = strlen(current);
		return (strlen(current));
	}

	
	// end condition
}

int	main(int argc, char **argv)
{
	char	*original_str;
	char	*current_str;

	if (argc < 2)
	{
		fprintt(1, "please enter a string of ( and )!");
		return (0);
	}
}
