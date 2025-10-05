#include <stdlib.h>

int	*race(int v1, int v2, int g)
{
	int	*ret;

	// return a heap-allocated array of 3 elements
	ret = calloc(3, sizeof(int));
	if (v1 >= v2)
	{
		for (int i = 0; i < 3; i++)
			ret[i] = -1;
		return (ret);
	}
	double t = (double)g / ((double)v2 - (double)v1); // time in hours
	ret[0] = (int)t;
	ret[1] = (t - ret[0]) * 60;
	ret[2] = (((t - ret[0]) * 60) - ret[1]) * 60; // think
	return (ret);
}

int	main(void)
{
	race(720, 600, 70);
}