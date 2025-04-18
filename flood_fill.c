
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

#include <stdlib.h>
#include <stdio.h>

void	helper(int **img, int m, int *n, int i, int j, int ogcol, int color);

int	**floodFill(int **image, int m, int *n, int sr, int sc, int color,
		int *returnSize, int **returnColumnSizes)
{
	int	i;
	int	**ret;
	int	ogcol;

	ogcol = image[sr][sc];
	ret = calloc(m , sizeof(int *));
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
	int m = 3;
	int n[max_per_arr] = {3, 3, 3};
	int image[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

	int returnSize;
	int *returnColumnSizes;
	int color = 2;

	int **imagePtr = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        imagePtr[i] = image[i];


    // Call the floodFill function
    int **result = floodFill(imagePtr, m, n, 1, 1, color, &returnSize, &returnColumnSizes);

    // Print the resulting image
    printf("Resulting Image:\n");
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < n[i]; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);
    free(returnColumnSizes);
    free(imagePtr);

}