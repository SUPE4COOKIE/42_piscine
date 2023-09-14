/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:11 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 16:30:24 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "prototypes.h"

int	read_nb_line(char *filename, int len);
int	read_char(char *filename, int start, t_map *map);
int	is_different(char str[3], t_map *map);
int	len_first_line(char *filename);

int	read_first_line(char *filename, t_map *map)
{
	int	len;

	len = len_first_line(filename);
	if (len == -1)
		return (0);
	map->height = read_nb_line(filename, len - 3);
	if (map->height == -1)
		return (0);
	if (!read_char(filename, len - 3, map))
		return (0);
	return (1);
}

int	len_first_line(char *filename)
{
	char	buffer[1];
	int		fd;
	int		rd;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	rd = 1;
	len = 0;
	while (rd)
	{
		rd = read(fd, buffer, 1);
		if (rd == -1)
			return (0);
		if (buffer[0] == '\n')
			break ;
		len++;
	}
	if (len <= 3)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (len);
}

int	read_nb_line(char *filename, int len)
{
	char	*buffer;
	int		fd;
	int		rd;
	int		nb;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	rd = read(fd, buffer, len);
	if (rd == -1)
		return (-1);
	buffer[len] = '\0';
	nb = ft_atoi(buffer);
	if (close(fd) == -1)
		return (-1);
	free(buffer);
	return (nb);
}

int	read_char(char *filename, int start, t_map *map)
{
	char	buffer[3];
	int		fd;
	int		rd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < start)
	{
		rd = read(fd, buffer, 1);
		if (rd == -1)
			return (0);
		i++;
	}
	rd = read(fd, buffer, 3);
	if (rd == -1)
		return (0);
	if (!is_different(buffer, map) || close(fd) == -1)
		return (0);
	return (1);
}

int	is_different(char str[3], t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = i + 1;
		while (j < 3)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	map->empty = str[0];
	map->barrier = str[1];
	map->full = str[2];
	return (1);
}
