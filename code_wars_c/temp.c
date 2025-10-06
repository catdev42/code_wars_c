/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:43:58 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/23 23:46:17 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int lenhex(int num)
{
	int len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

int main(void)
{
	int num = 32;
	char *str = "hello";

	printf("%x\n", num);
	printf("%d\n", lenhex(num));
	return 0;
}