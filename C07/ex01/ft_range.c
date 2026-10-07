/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:13:40 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/17 11:13:43 by migarci3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	i = 0;
	if (min >= max)
		return (NULL);
	array = (int *) malloc((max - min) * sizeof(int));
	while (min + i < max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
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
