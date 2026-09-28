/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:54:08 by acornia           #+#    #+#             */
/*   Updated: 2026/09/22 09:45:45 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	counter;

	counter = 'a';
	while (counter <= 'z')
	{
		ft_putchar(counter);
		counter++;
	}
}

// int main(void)
// {
//         ft_print_alphabet();
//         return(0);
// }