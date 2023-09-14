/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:12:36 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/23 22:55:34 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verify_dict.h"

int	str_check(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '\n')
		return (1);
	while (c[i] != 32)
		if (c[i] >= '0' && c[i] <= '9')
			i++;
	while (c[i] != ':')
		if (c[i] == 32)
			i++;
	while (!(c[i] >= 32 && c[i] <= 126))
		if (c[i] == 32)
			i++;
	while (c[i] != '\n')
	{
		if (!(c[i] >= 32 && c[i] <= 126))
			return (0);
		i++;
	}
	if (c[i] == '\n')
		return (1);
	return (0);
}

int	check_lines(int fd, char *line)
{
	int		byte_read;
	char	c;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read (fd, &c, 1);
		line = append(line, c);
		if (c == '\n')
		{
			if (!str_check(line))
				return (0);
			line[0] = '\0';
		}
	}
	return (1);
}

int	is_dict_valid(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write (2, "file error\n", 11);
		return (-1);
	}
	line = malloc(1);
	line[0] = '\0';
	if (!check_lines(fd, line))
		return (0);
	return (1);
	close(fd);
}
