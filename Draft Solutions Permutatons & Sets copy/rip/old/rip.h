#ifndef RIP_H
#define RIP_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_solution_node
{
	char *str;
	struct s_solution_node *next;
}	t_solnode;

#endif