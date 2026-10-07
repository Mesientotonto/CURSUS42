/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:20:39 by acornia           #+#    #+#             */
/*   Updated: 2026/08/25 13:07:43 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int	main(void)
{
	ft_strlen("hola");
	printf("La longitud de la palabra es: %d\n", ft_strlen("hola"));
	return (0);
}

