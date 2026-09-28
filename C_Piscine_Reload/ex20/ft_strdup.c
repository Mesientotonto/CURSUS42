/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:01:16 by acornia           #+#    #+#             */
/*   Updated: 2026/09/22 13:18:08 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	*ori;
// 	char	*cop;

// 	ori = "Hola que tal";
// 	cop = ft_strdup(ori);
// 	if (!cop)
// 		return (1);
// 	printf("Original: %s.\n", ori);
// 	printf("Copia: %s", cop);
// 	free(cop);
// 	return (0);
// }
