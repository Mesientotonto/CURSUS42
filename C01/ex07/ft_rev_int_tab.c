/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:02:45 by acornia           #+#    #+#             */
/*   Updated: 2026/08/30 11:31:03 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;
	int	a;

	counter = 0;
	while (counter < size)
	{
		a = tab[(size -1)];
		tab[(size -1)] = tab[counter];
		tab[counter] = a;
		size --;
		counter ++;
	}
}

int	main(void)
{
	int	array[5] = {1,2,3,4,5};
	int i;

	ft_rev_int_tab(array, 5);

	i = 0;
	while (i < 5)
	{
		printf("%d ", array[i]);
		i++;
	}
	return (0);
}