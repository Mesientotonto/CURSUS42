/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:37:56 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/18 12:56:51 by migarci3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	range[0] = (int *) malloc((max - min) * sizeof(int ));
	while (min + i < max)
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}
/*
int main(void)
{
    int min = -6;
    int max = 17;
    printf("%p \n", ft_range(min, max));
    for (int i = 0; i + min < max; i++)
    {
        printf("%d ", (ft_range(min, max))[i]);
    }
    printf("\n");
    return(0);
}
*/
