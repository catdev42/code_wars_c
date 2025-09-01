#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void change_nums(int start, int current, int *change)
{
	if (current > start)
		return;
	printf("%d  ", current);
	if (current < 0)
		*change = *change * -1;
	change_nums(start, current + *change, change);
}
void simple(int num)
{
	if (num < 0)
	{
		printf("%d  ", num);
		return;
	}
	printf("%d  ", num);
	simple(num - 5);
	printf("%d  ", num);
}
int main(void)
{
	int start = 16;
	int current = start;
	int change = -5;

	change_nums(start, current, &change);
	printf("\n");

	simple(start);
}