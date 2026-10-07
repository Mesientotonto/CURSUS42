/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:25:30 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/17 15:25:32 by migarci3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strcat(char *dest, char src)
{
	int	l;

	l = ft_strlen(dest);
	dest[l] = src;
	dest[l + 1] = '\0';
	return (dest);
}
