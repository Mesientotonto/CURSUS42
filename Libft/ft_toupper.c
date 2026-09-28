/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:11:08 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 10:57:46 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_toupper (de to uppercase) es la opuesta a ft_tolower: 
toma un carácter y, si es una letra minúscula ('a' - 'z'), lo convierte 
a su correspondiente letra mayúscula ('A' - 'Z').*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	return (c);
}
