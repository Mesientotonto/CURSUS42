/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:46:22 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/18 13:07:32 by migarci3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (dest);
}

int	get_size(int size, char **strs, char *sep)
{
	int	i;
	int	l;

	i = 0;
	l = 1;
	while (i < size)
	{
		l = l + ft_strlen(strs[i]);
		if (i != size - 1)
			l = l + ft_strlen(sep);
		i++;
	}
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		l;
	char	*s;

	if (size <= 0)
	{
		s = (char *) malloc(sizeof(char));
		*s = '\0';
		return (s);
	}
	l = get_size(size, strs, sep);
	s = (char *) malloc((l + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		ft_strcat(s, strs[i]);
		if (i != size - 1)
			ft_strcat(s, sep);
		i++;
	}
	return (s);
}
/*
int main(void)
{
    char *strs[] = {"a bb ccc", "e eee ee ee", "OoO Oo"};
    char sep[] = " UWU ";
    printf("%s", ft_strjoin(3, strs, sep));
    return(0);
}
*/
