/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:54:01 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 18:05:46 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "prototypes.h"
#include "includes.h"

int	fill_square(t_map *map, int i, int j);

void	print_board(t_tile **board, int length, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length - 1)
		{
			write (1, &(board[i][j].value), 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	search_max(t_map *map)
{
	int	max;
	int	indexes[4];

	max = 0;
	indexes[0] = 0;
	while (indexes[0] < map->height)
	{
		indexes[1] = 0;
		while (indexes[1] < map->length)
		{
			if (map->board[indexes[0]][indexes[1]].max_square > max)
			{
				max = map->board[indexes[0]][indexes[1]].max_square;
				indexes[3] = indexes[1];
				indexes[2] = indexes[0];
			}
			indexes[1]++;
		}
		indexes[0]++;
	}
	if (max == 0)
		return (0);
	return (fill_square(map, indexes[2], indexes[3]));
}

int	fill_square(t_map *map, int i, int j)
{
	int	temp_j;
	int	temp_i;
	int	size;

	size = map->board[i][j].max_square;
	temp_i = i;
	while (temp_i < i + size)
	{
		temp_j = j;
		while (temp_j < j + size)
		{
			map->board[temp_i][temp_j].value = map->full;
			temp_j++;
		}
		temp_i++;
	}
	return (1);
}

int	loop_arg(int argc, char **argv, t_map *map)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		map = read_file(argv[i]);
		if (!map)
			return (error());
		else
		{
			recursive(map, 0, 0);
			search_max(map);
			print_board(map->board, map->length, map->height);
			free_map(map->board, map->height);
			free(map);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = NULL;
	if (argc == 1)
	{
		map = read_term();
		if (!map)
			return (error());
		recursive(map, 0, 0);
		search_max(map);
		print_board(map->board, map->length, map->height);
		free_map(map->board, map->height);
		free(map);
	}
	return (loop_arg(argc, argv, map));
}
