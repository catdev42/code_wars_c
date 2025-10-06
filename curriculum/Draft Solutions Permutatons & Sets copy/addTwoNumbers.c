struct				ListNode
{
	int				val;
	struct ListNode	*next;
};

/* Have to rewrite without using intermediate numbers
It seems that the point of the assignment is to be able to deal with numbers as arrays thus avoiding the limitations of max int / max long / uint etc... avoid system limitations of byte sized to store numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	long long int		i;
	long long int		j;
	long long int		multiplier;
	struct ListNode		*temp;
	struct ListNode		*ret;
	unsigned long int	num1;
	unsigned long int	num2;

	i = 1;
	j = 0;
	multiplier = 1;
	num1 = l1->val;
	num2 = l2->val;
	temp = l1;
	while (temp->next)
	{
		temp = temp->next;
		multiplier = 1;
		j = 0;
		while (j < i)
		{
			multiplier *= 10;
			j++;
		}
		num1 = num1 + temp->val * multiplier;
		i++;
	}
	i = 1;
	temp = l2;
	while (temp->next)
	{
		temp = temp->next;
		multiplier = 1;
		j = 0;
		while (j < i)
		{
			multiplier *= 10;
			j++;
		}
		num2 = num2 + temp->val * multiplier;
		i++;
	}
	num1 += num2;
	temp = l1;
	if (!temp)
		exit(1);
	ret = temp;
	temp->val = num1 % 10;
	num1 = num1 / 10;
	while (num1 != 0)
	{
		if (temp->next)
		{
			temp = temp->next;
			temp->val = num1 % 10;
		}
		else
		{
			temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			temp = temp->next;
			temp->next = NULL;
			temp->val = num1 % 10;
		}
		num1 = num1 / 10;
	}
	return (ret);
}

int	main(void)
{
	int num1;
	int num2;
	int numtotal;
	struct ListNode *l1;
	struct ListNode *l2;
	struct ListNode *temp;

	num1 = 234;
	num2 = 567;
	numtotal = num1 + num2;

	temp = malloc(1 * sizeof(struct ListNode));
	if (!temp)
		exit(1);
	l1 = temp;
	temp->val = num1 % 10;
	num1 = num1 / 10;
	while (num1 != 0)
	{
		temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp = temp->next;
		temp->val = num1 % 10;
		num1 = num1 / 10;
	}

	temp = malloc(1 * sizeof(struct ListNode));
	if (!temp)
		exit(1);
	l2 = temp;
	temp->val = num2 % 10;
	num2 = num2 / 10;
	while (num2 != 0)
	{
		temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp = temp->next;
		temp->val = num2 % 10;
		num2 = num2 / 10;
	}
	addTwoNumbers(l1, l2);
}