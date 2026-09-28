/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:41:09 by acornia           #+#    #+#             */
/*   Updated: 2026/09/23 13:00:46 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	display_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUF_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	bytes_read = read(fd, buffer, BUF_SIZE);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, BUF_SIZE);
	}
	if (bytes_read < 0)
		ft_putstr("Cannot read file.\n");
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		display_file(argv[1]);
	return (0);
}
