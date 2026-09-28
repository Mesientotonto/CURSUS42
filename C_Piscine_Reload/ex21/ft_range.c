/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:28:54 by acornia           #+#    #+#             */
/*   Updated: 2026/09/23 16:21:30 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (max - min));
	if (!range)
		return (NULL);
	i = 0;
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}

#include <stdio.h>

int	main(void)
{
	int	*array;
	int	min;
	int	max;
	int	i;
	int	size;

	min = 5;
	max = 10;
	size = max - min;
	array = ft_range(min, max);
	if (!array)
		return (1);
	i = 0;
	while (i < size)
	{
		printf("Array[%d] = %d.\n", i, array[i]);
		i++;
	}
	free(array);
	return (0);
}