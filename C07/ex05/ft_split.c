/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 00:21:59 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/18 13:27:53 by migarci3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	find_char(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_num_words(char *str, char *charset)
{
	int		i;
	int		num_palabras;

	i = 0;
	num_palabras = 0;
	while (str[i] != 0)
	{
		if (find_char(str[i], charset))
		{
			num_palabras++;
			while (str[i + 1] != 0 && find_char(str[i], charset))
				i++;
		}
		i++;
	}
	return (num_palabras);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		num_palabras;
	char	**s;

	s = (char **) malloc((1 + get_num_words(str, charset)) * sizeof(char *));
	s[get_num_words(str, charset)] = NULL;
	num_palabras = 0;
	while (*str != 0)
	{
		i = 0;
		if (find_char(str[i], charset) != -1)
		{
			while (str[i] != 0 && find_char(str[i], charset) != -1)
				i++;
		}
		else
		{
			while (str[i] != 0 && find_char(str[i], charset) == -1)
				i++;
			s[num_palabras] = (char *) malloc((i + 1) * sizeof(char));
			ft_strncpy(s[num_palabras++], str, i);
		}
		str = str + i;
	}
	return (s);
}
/*
int main(void)
{
    char a[] = "aa bbb  cccc .. ddddd";
    char b[] = " .";
    char **c = ft_split(a, b);
    printf("%s\n",c[0]);
    printf("%s\n",c[1]);
    printf("%s\n",c[2]);
    printf("%s\n",c[3]);
    printf("%s\n",c[4]);
    return(0);
}
*/
