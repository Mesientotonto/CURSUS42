/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 10:29:20 by acornia           #+#    #+#             */
/*   Updated: 2026/09/01 11:59:10 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_rec(int nbr, char *base, int len)
{
	if (nbr >= len)
		ft_putnbr_rec(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (!ft_check_base(base))
		return ;
	len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_rec(-(nbr / len), base, len);
		write(1, &base[-(nbr % len)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	ft_putnbr_rec(nbr, base, len);
}

int	main(void)
{
	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);

	ft_putnbr_base(42, "01");
	write(1, "\n", 1);

	ft_putnbr_base(42, "0123456789ABCDEF");
	write(1, "\n", 1);

	ft_putnbr_base(42, "poneyguay");
	write(1, "\n", 1);
}