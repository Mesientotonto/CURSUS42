/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:01:16 by acornia           #+#    #+#             */
/*   Updated: 2026/08/30 11:38:29 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new;

	i = 0;
	new = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (new == 1 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
			new = 0;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			new = 0;
		else
			new = 1;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str[]= "salut, comment tu vas ?"
		" 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str));
	return(0);
}

