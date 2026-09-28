/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:41:59 by acornia           #+#    #+#             */
/*   Updated: 2026/09/23 12:00:53 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (!tab || !f || length <= 0)
		return ;
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// #include <stdio.h>

// void	ft_putnbr(int n)
// {
// 	printf("%d\n", n);
// }

// int	main(void)
// {
// 	int	numbers[] = {1, 2, 42, 100, -5};
// 	ft_foreach(numbers, 5, &ft_putnbr);
// 	return (0);
// }
