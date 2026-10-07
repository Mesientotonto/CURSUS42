/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:37:58 by acornia           #+#    #+#             */
/*   Updated: 2026/08/30 11:46:17 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') && i < n - 1)
	{
		i++;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

int	main(void)
{
	printf("%d\n", ft_strncmp("hola", "hola", 2));
	printf("%d\n", ft_strncmp("hola", "holagh", 6));
	printf("%d\n", ft_strncmp("hola", "h0la", 3));
	return (0);
}

