/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:39:03 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 10:34:34 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_calloc (de contiguous allocation) se utiliza para reservar 
memoria dinámica en el heap y limpiarla poníendola toda a cero (0).*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
