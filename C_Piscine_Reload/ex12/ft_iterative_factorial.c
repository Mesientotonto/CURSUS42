/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:06:46 by acornia           #+#    #+#             */
/*   Updated: 2026/09/22 15:12:58 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

// #include <stdio.h>

// int	main()
// {
// 	int	num;

// 	num = 7;
// 	printf("%d", ft_iterative_factorial(num));
// 	return (0);
// }