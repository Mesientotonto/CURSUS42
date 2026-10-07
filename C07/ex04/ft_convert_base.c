/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:25:10 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/18 13:15:04 by migarci3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char src);
int		check_base(char *base);
int		is_base(char c, char *base);
int		ft_strlen(char *str);

char	*ft_putnbr_base(int nbr, char *s, char *base, int cifras)
{
	long	n;
	int		l;

	l = ft_strlen(base);
	n = (long) nbr;
	if (n < 0)
	{
		n = -1 * n;
		cifras++;
	}
	if (n < (long)l)
	{
		cifras++;
		s = (char *) malloc((cifras + 1) * sizeof(char));
		if (nbr < 0)
			ft_strcat(s, '-');
		ft_strcat(s, base[(int) n]);
		return (s);
	}
	else
	{
		s = ft_putnbr_base(nbr / l, s, base, cifras + 1);
		ft_strcat(s, base[(int)(n % ((long) l))]);
		return (s);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	int		sign;
	int		i;
	char	*s;

	n = 0;
	i = 0;
	sign = 1;
	s = NULL;
	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	while (nbr[i] != 0 && (nbr[i] == ' ' || (nbr[i] <= '\r' && nbr[i] >= '\t')))
		i++;
	while (nbr[i] != 0 && (nbr[i] == '+' || nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (nbr[i] != 0 && is_base(nbr[i], base_from) != -1)
	{
		n = n * ft_strlen(base_from) + is_base(nbr[i], base_from);
		i++;
	}
	return (ft_putnbr_base(sign * n, s, base_to, 0));
}

/*
int main(void)
{
    char a[] = "    ---BCDEab567";
    char b[] = "ABCDEFGHIJ";
    char c[] = "0123456789";
    printf("%s \n",ft_convert_base(a, b, c));
    return(0);
}
*/
