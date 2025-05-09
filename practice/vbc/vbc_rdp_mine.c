#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	enum
	{
		ADD,
		MULTI,
		VAL
	} type;
	int val;
	struct node *l;
	struct node *r;
} node;

node *if_lowest_prio(char **s);

node *new_node(node n)
{
	node *ret;

	ret = calloc(1, sizeof(node));
	if (!ret)
		return (NULL);
	*ret = n;
	return (ret);
}

void destroy_tree(node *n)
{
	if (!n)
		return;
	if (n->type != VAL)
	{
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void unexpected_char(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input \n");
}

int accept(char **s, char c)
{
	if (**s == c)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

int expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected_char(**s);
	return (0);
}

int eval_tree(node *tree)
{
	switch (tree->type)
	{
	case ADD:
		return (eval_tree(tree->l) + eval_tree(tree->r));
	case MULTI:
		return (eval_tree(tree->l) * eval_tree(tree->r));
	case VAL:
		return (tree->val);
	}
}
// node *get_num_node(char **s);

/* parenthesis or number (leaf nodes,
things that come later in tree but first in calculations and should be on the bottom,
get them first) */
node *if_high_prio(char **s);
node *if_mid_prio(char **s);
node *if_low_prio(char **s);

node *get_num_node(char **s)
{
	node ret;
	if (**s >= '0' && **s <= '9')
	{
		ret.type = VAL;
		ret.val = atoi(*s);
		if (ret.val > 9)
		{
			unexpected_char(**(s + 1));
			exit(1);
		}
		ret.l = NULL;
		ret.r = NULL;
		accept(s, **s);
	}
	else
		return NULL;
	return (new_node(ret));
}

/* parenthesis or number (leaf nodes,
things that come later in tree but first in calculations and should be on the bottom,
get them first) */
node *if_high_prio(char **s)
{
	node *left;

	if (accept(s, '('))
	{
		left = if_low_prio(s); // start whole thing over until ')'
		if (!expect(s, ')'))
		// if you dont find a closing parenthesis after all that
		{
			unexpected_char(**s);
			exit(1);
		}
		return (left);
	}
	else
		return get_num_node(s);
}

//if there is multi node make a node else just return the number node or the parenthesis branch
node *if_mid_prio(char **s) 
{
	node *left;

	left = if_high_prio(s);
	if (accept(s, '*'))
	{
		node ret;
		ret.type = MULTI;
		ret.l = left;
		ret.r = if_low_prio(s);
		return (new_node(ret));
	}
	return left; // to if low prio
}

node *if_low_prio(char **s)
{
	node *left;

	left = if_mid_prio(s);
	if (accept(s, '+'))
	{
		node ret;
		ret.type = ADD;
		ret.l = left;
		ret.r = if_low_prio(s);
		return (new_node(ret));
	}
	return left;
}

node *parse_expr(char *s)
{
	node *ret;

	ret = if_low_prio(&s);
	if (*s)
	{
		unexpected_char(*s);
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *input = argv[1];
	node *tree = parse_expr(input);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);
}