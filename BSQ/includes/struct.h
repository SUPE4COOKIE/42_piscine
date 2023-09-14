/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:07:25 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 16:17:14 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_tile
{
	char	value;
	int		max_square;
}	t_tile;

typedef struct s_map
{
	int		height;
	int		length;
	char	empty;
	char	full;
	char	barrier;
	t_tile	**board;
}	t_map;

#endif
