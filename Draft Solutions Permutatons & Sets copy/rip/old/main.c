#include "rip.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	size;

	if (argc < 2)
		write(1, "Please give an argument\n", 24);
	size = strlen(argv[1]);
	if (size == 0)
		return (0);
	rip(argv[1]);
}

	rip(char *str);


t_solnode	*makeNode(char *str, t_solnode *start)
{
	t_solnode	*temp;

	temp = start;
	while (temp->next)
		temp = temp->next;
	temp->next = malloc(sizeof(t_solnode));
	if (temp->next == NULL)
		free_all(start);
	temp = temp->next;
}

free_all(t_solnode *start)
{
	t_solnode *temp;
	t_solnode *node_to_free;
	temp = start;
	while (temp->next)
	{
		free(temp->str);
		node_to_free = temp;
		temp = temp->next;
		free(node_to_free);
	}
	exit(1);
}