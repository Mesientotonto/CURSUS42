/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:27:07 by acornia           #+#    #+#             */
/*   Updated: 2026/09/23 11:58:48 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

// #include <stdio.h>

// int	has_a(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == 'a')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	char	*palabras[] = {"hola", "que", "tal", 0};
// 	int	resultado;
// 	resultado = ft_count_if(palabras, &has_a);
// 	printf("%d", resultado);
// 	return (0);
// }