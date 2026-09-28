/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 10:27:00 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 10:38:51 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_memmove (de memory move) copia $n$ bytes de una zona de memoria 
de origen (src) a una de destino (dst), pero con una ventaja crucial sobre 
memcpy: es completamente segura ante solapamiento de memoria (overlapping).*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;

	if (!dest && !src)
		return (NULL);
	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	if (str1 > str2)
	{
		while (n > 0)
		{
			n--;
			str1[n] = str2[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
