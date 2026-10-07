/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:59:14 by migarci3          #+#    #+#             */
/*   Updated: 2026/08/18 12:52:52 by migarci3         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		i;
	int		l;
	char	*dest;

	i = 0;
	l = ft_strlen(src);
	dest = (char *) malloc(l * sizeof(char ));
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
/*
int main(void)
{
    char a[] = "hola";
    printf("%s, %p, %s, %p \n",a ,a ,ft_strdup(a), ft_strdup(a));
    return(0);
}
*/
