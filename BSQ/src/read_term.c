/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:57:48 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 17:47:27 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "prototypes.h"

int	read_all_term(t_map *map);
int	read_second_term_line(t_map *map, int len);
int	fill_char_map(t_map *map, char *str);
int	read_first_term_line(t_map *map);

t_map	*read_term(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!read_first_term_line(map))
		return (NULL);
	map->board = malloc(sizeof(t_tile *) * map->height);
	if (!map->board)
	{
		free(map);
		return (NULL);
	}
	if (!read_second_term_line(map, 1))
	{
		free_map(map->board, map->height);
		return (NULL);
	}
	if (!read_all_term(map))
	{
		free_map(map->board, map->height);
		return (NULL);
	}
	return (map);
}

int	read_first_term_line(t_map *map)
{
	char	*str;
	char	buffer[1];
	int		rd;

	str = malloc(sizeof(char));
	if (!str)
		return (0);
	rd = read(0, str, 1);
	if (rd == -1 || rd == 0)
		return (free_str(str));
	while (rd)
	{
		rd = read(0, buffer, 1);
		if (rd == -1)
			return (free_str(str));
		if (buffer[0] == '\n')
			break ;
		str = append(str, buffer[0]);
	}
	return (fill_char_map(map, str));
}

int	fill_char_map(t_map *map, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4 || str[len - 1] == str[len - 2] || str[len - 1] == str[len - 3]
		|| str[len - 2] == str[len - 3])
	{
		free(str);
		return (0);
	}
	map->empty = str[len - 3];
	map->barrier = str[len - 2];
	map->full = str[len - 1];
	str[len - 3] = '\0';
	map->height = ft_atoi(str);
	free(str);
	if (map->height == -1)
		return (0);
	return (1);
}

int	read_second_term_line(t_map *map, int len)
{
	char	*str;
	char	buffer[1];
	int		rd;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	rd = read(0, str, 1);
	if (rd == -1 || rd == 0)
		return (free_str(str));
	str[1] = '\0';
	while (rd)
	{
		rd = read(0, buffer, 1);
		if (rd == -1)
			return (free_str(str));
		if (++len && buffer[0] == '\n')
			break ;
		str = append(str, buffer[0]);
	}
	map->length = len;
	map->board[0] = ft_strdup(str, len, map);
	if (!map->board[0])
		return (free_str(str));
	return (!free_str(str));
}

int	read_all_term(t_map *map)
{
	char	*str;
	int		rd;
	int		i;

	str = malloc(sizeof(char) * (map->length + 1));
	if (!str)
		return (0);
	rd = 1;
	i = 1;
	while (i < map->height)
	{
		rd = read(0, str, map->length + 1);
		if (rd == -1)
			return (free_str(str));
		map->board[i] = ft_strdup(str, rd, map);
		if (!map->board[i])
			return (free_str(str));
		i++;
	}
	free(str);
	return (1);
}
