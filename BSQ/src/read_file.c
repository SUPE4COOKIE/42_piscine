/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:06:05 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 16:29:44 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "prototypes.h"

int	col_len(char *filename);

t_map	*read_file(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!read_first_line(filename, map))
	{
		free(map);
		return (NULL);
	}
	map->length = col_len(filename);
	if (map->length == -1)
	{
		free(map);
		return (NULL);
	}
	map->board = save_file(filename, map);
	if (map->board == NULL)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

int	col_len(char *filename)
{
	char	buffer[1];
	int		fd;
	int		rd;
	int		len;
	int		boolean;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	rd = 1;
	len = 0;
	boolean = 0;
	while (rd)
	{
		rd = read(fd, buffer, 1);
		if (rd == -1)
			return (-1);
		if (boolean == 1)
			len++;
		if (buffer[0] == '\n')
			boolean++;
		if (boolean == 2)
			break ;
	}
	return (len);
}

void	*free_map(t_tile **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
	return (NULL);
}
