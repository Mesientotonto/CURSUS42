/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:23:19 by acornia           #+#    #+#             */
/*   Updated: 2026/08/16 16:56:47 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	number;

	number = ('0');
	while (number <= '9')
	{
		write(1, &number, 1);
		number++;
	}
}

int main(void)
{
	ft_print_numbers();
	return(0);
}

