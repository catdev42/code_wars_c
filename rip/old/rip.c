#include "rip.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 Personal notes:
keep track of how many parenthesis we are removing....
if it is 1, find all answers with 1 ,
if it is 2, find only answers with 2

Keeping track of which index we are at
	- reset if we go to removing more parenthesis - aka 2 or 3....
 */
// return -1 if too many closing brackets
//return 0
int	isvalid(char *str)
{
	int	balance;
	int	i;

	balance = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			balance++;
		if (str[i] == ')')
		{
			balance--;
			if (balance < 0)
				return (-1);
		}
		i++;
	}
	if (balance == 0)
		return (1);
	return (0);
}

void removeInvalidParentheses(char *s)
{
	int i = 0;

	if (isvalid(s))
	{
		printf("%s\n", s);
		return ;
	}

}
