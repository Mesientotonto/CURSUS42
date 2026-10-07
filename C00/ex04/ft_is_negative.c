/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:19:06 by acornia           #+#    #+#             */
/*   Updated: 2026/08/31 13:27:19 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_is_negative(int n)
{
	char	answer;

	if (n < 0)
	{
		answer = 'N';
		write(1, &answer, 1);
	}
	else
	{
		answer = 'P';
		write(1, &answer, 1);
	}
}

int	str_to_int(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int main(int argc, char **argv)
{
	int	num;

	if (argc == 2)
	{
		num = str_to_int(argv[1]);
		printf("El numero es: %d.\n", num);
		ft_is_negative(num);
		return (0);
	}
	return (0);
}

