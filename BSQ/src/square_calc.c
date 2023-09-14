/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:44:45 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/25 16:17:01 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <unistd.h>

int	min_direction(int vertical, int horizontal, int diagonal)
{
	if ((vertical <= horizontal) && (vertical <= diagonal))
		return (vertical);
	else if ((horizontal <= vertical) && (horizontal <= diagonal))
		return (horizontal);
	else
		return (diagonal);
}

int	recursive(t_map *map, int i, int j)
{
	int	v;
	int	h;
	int	d;

	if (j == map->length - 1)
		return (0);
	if (i == map->height)
		return (0);
	if (map->board[i][j].max_square != -1)
		return (map->board[i][j].max_square);
	v = recursive(map, (i + 1), j);
	h = recursive(map, i, (j + 1));
	d = recursive(map, (i + 1), (j + 1));
	if (map->board[i][j].value == map->barrier)
	{
		map->board[i][j].max_square = 0;
		return (0);
	}
	map->board[i][j].max_square = 1 + min_direction(v, h, d);
	return (map->board[i][j].max_square);
}
