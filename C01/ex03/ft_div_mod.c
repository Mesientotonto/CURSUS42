/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:36:38 by acornia           #+#    #+#             */
/*   Updated: 2026/08/19 14:30:45 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 10;
	b = 3;

	ft_div_mod(a, b, &div, &mod);
	printf("%d %d\n", div, mod);
	return(0);
}

