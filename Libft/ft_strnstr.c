/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:06:50 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 10:55:15 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_strnstr busca la primera ocurrencia de una subcadena de texto 
(little) dentro de una cadena más grande (big), pero limitando la búsqueda a 
un número máximo de caracteres (len).*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	s1;
	size_t	s2;

	if (little[0] == '\0')
		return ((char *)big);
	s1 = 0;
	while (big[s1] != '\0' && s1 < len)
	{
		s2 = 0;
		while (big[s1 + s2] == little[s2] && (s1 + s2) < len)
		{
			if (little[s2 + 1] == '\0')
				return ((char *)&big[s1]);
			s2++;
		}
		s1++;
	}
	return (NULL);
}
