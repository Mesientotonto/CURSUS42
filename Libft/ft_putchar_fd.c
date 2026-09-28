/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:26:41 by acornia           #+#    #+#             */
/*   Updated: 2026/09/28 10:47:27 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función ft_putchar_fd escribe un único carácter en un descriptor de 
archivo (file descriptor o fd) específico.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
