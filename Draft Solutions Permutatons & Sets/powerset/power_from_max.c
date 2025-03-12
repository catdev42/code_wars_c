/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_from_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:16:51 by mkokorev          #+#    #+#             */
/*   Updated: 2025/01/23 18:13:36 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// docker run -it -v ${pwd}:/home/root ubuntu

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_parce(char **argv, int num, int *first)
{
	int	*arr;
	int	i;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * num);
	if (!arr)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return (NULL);
	}
	*first = atoi(argv[1]);
	while (i < num)
	{
		arr[i] = atoi(argv[i + 2]);
		i++;
	}
	return (arr);
}

void	ft_print_arr_space(int *arr, int num)
{
	int	i;
	
	i = 0;
	while (i < num)
	{
		fprintf(stdout, "%d ", arr[i]);
		i++;
	}
	fprintf(stdout, "\n");
}

void	find_set(int idx, int num, int *arr, int first, int sum, int *subset, int subset_size)
{
	if (sum == first)
	{
		ft_print_arr_space(subset, subset_size);
		return ;
	}
	if (sum > first || idx >= num )
	{
		return;
	}
	subset[subset_size] = arr[idx];
	//try woth the next number in subset if we add it:
	find_set(idx + 1, num, arr, first, sum + arr[idx], subset, subset_size + 1);
	//try if not add: we move but don't add
	find_set(idx + 1, num, arr, first, sum, subset, subset_size);
}

int main (int argc, char **argv)
{
	int *arr;
	int num;
	int first;
	int *subset;
	
	if (argc < 3)
	{
		fprintf(stdout, "put more arguments!\n");
		return (0);
	}
	num = argc - 2;
	arr = ft_parce(argv, num, &first);
	if (!arr)
		return (1);
	subset = (int *)malloc(sizeof(int) * num);
	if (!subset)
	{
		free(arr);
		return (1);
	}
	find_set(0, num, arr, first, 0, subset, 0);
	free(arr);
	free(subset);
	return (0);
}