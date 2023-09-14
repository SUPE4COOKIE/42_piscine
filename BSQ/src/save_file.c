/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:48:24 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 16:31:17 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "prototypes.h"

int		is_possible(char c, t_map *map);
int		skip_first_line(char *filename);
t_tile	*copy_map(int fd, t_map *map);

t_tile	**save_file(char *filename, t_map *map)
{
	int		fd;
	t_tile	**board;
	int		i;

	board = malloc(sizeof(t_tile *) * map->height);
	if (!board)
		return (NULL);
	fd = skip_first_line(filename);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		board[i] = copy_map(fd, map);
		if (!board[i])
			return (free_map(board, i));
	}
	if (close(fd) == -1)
		return (free_map(board, i));
	return (board);
}

int	skip_first_line(char *filename)
{
	int		fd;
	char	buffer[1];
	int		rd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	rd = 1;
	while (rd)
	{
		rd = read(fd, buffer, 1);
		if (rd == -1)
			return (-1);
		if (buffer[0] == '\n')
			break ;
	}
	return (fd);
}

t_tile	*copy_map(int fd, t_map *map)
{
	t_tile	*line;
	char	*buffer;
	int		rd;

	buffer = malloc(sizeof(char) * map->length);
	if (!buffer)
		return (NULL);
	rd = read(fd, buffer, map->length);
	if (rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_strdup(buffer, rd, map);
	free(buffer);
	if (!line)
		return (NULL);
	return (line);
}

int	is_possible(char c, t_map *map)
{
	if (c == map->empty || c == map->barrier)
		return (1);
	return (0);
}
