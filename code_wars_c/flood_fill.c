/*
m >= 1
n < = 50
values of color >= 0 && color <= 2^16 (65536) (2 bytes)
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

void	helper(int **img, int m, int *n, int i, int j, int ogcol, int color);

int	**floodFill(int **image, int m, int *n, int sr, int sc, int color,
		int *returnSize, int **returnColumnSizes)
{
	int	i;
	int	**ret;
	int	ogcol;

	ogcol = image[sr][sc];
	ret = calloc(m, sizeof(int *));
	*returnColumnSizes = calloc(m, sizeof(int));
	*returnSize = m;
	if (!ret || !returnColumnSizes)
		exit(1);
	i = 0;
	while (i < m)
	{
		(*returnColumnSizes)[i] = n[i];
		ret[i] = calloc(n[i], sizeof(int));
		if (!ret[i])
			exit(1);
		for (int j = 0; j < n[i]; j++)
			ret[i][j] = image[i][j]; // wrote into array from given
		i++;
	}
	if (ogcol == color)
		return (ret);
	helper(ret, m, n, sr, sc, ogcol, color);
	return (ret);
}

void	helper(int **img, int m, int *n, int i, int j, int ogcol, int color)
{
	if (img[i][j] != ogcol)
		return ;
	else
		(img[i][j] = color);
	if (i >= 1 && img[i - 1][j] == ogcol)
		helper(img, m, n, i - 1, j, ogcol, color);
	if (j >= 1 && img[i][j - 1] == ogcol)
		helper(img, m, n, i, j - 1, ogcol, color);
	if (j < n[i] - 1 && img[i][j + 1] == ogcol)
		helper(img, m, n, i, j + 1, ogcol, color);
	if (i < m - 1 && img[i + 1][j] == ogcol)
		helper(img, m, n, i + 1, j, ogcol, color);
}

#define max_per_arr 3

int	main(void)
{
	int	m;
	int	n[max_per_arr] = {3, 3, 3};
	int	**image;
	int	*nptr;
	int	returnSize;
	int	*returnColumnSizes;
	int	color;
	int	**result;

	m = 3;
	// Create dynamic 2D array for image
	image = malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
	{
		image[i] = malloc(n[i] * sizeof(int));
	}
	// Initialize image data
	// First row
	image[0][0] = 1;
	image[0][1] = 1;
	image[0][2] = 1;
	// Second row
	image[1][0] = 1;
	image[1][1] = 1;
	image[1][2] = 0;
	// Third row
	image[2][0] = 1;
	image[2][1] = 0;
	image[2][2] = 1;
	nptr = n;
	color = 2;
	// Call floodFill
	result = floodFill(image, m, nptr, 1, 1, color, &returnSize,
			&returnColumnSizes);
	// Print result
	printf("Result after flood fill:\n");
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < returnColumnSizes[i]; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	// Free memory
	for (int i = 0; i < m; i++)
	{
		free(image[i]);
		free(result[i]);
	}
	free(image);
	free(result);
	free(returnColumnSizes);
	return (0);
}

// int	main(void)
// {
// 	int m = 3;
// 	int n[max_per_arr] = {3, 3, 3};

// 	int image[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

// 	// int **imageptr = &image;
// 	int *nptr = &n[0];
// 	int returnSize;
// 	int *returnColumnSizes;
// 	int color = 2;

// 	int **temp = floodFill(image, m, nptr, 1, 1, color, &returnSize,
// 			&returnColumnSizes);
// }