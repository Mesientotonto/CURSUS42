/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:43:50 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 15:58:53 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_putstr_fd (de put string on file descriptor) toma una cadena 
de caracteres y la escribe completa en el descriptor de archivo 
(file descriptor o fd) especificado.*/

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
		ft_putchar_fd(*(s++), fd);
}
