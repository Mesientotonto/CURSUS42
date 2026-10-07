/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:03:40 by acornia           #+#    #+#             */
/*   Updated: 2026/08/30 11:37:49 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	char	test[] = "hola\tmundo";
	
	printf("%d\n", ft_str_is_printable("hola"));
	printf("%d\n", ft_str_is_printable(test));
	return (0);
}
