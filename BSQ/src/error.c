/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:50:57 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/25 16:54:01 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "prototypes.h"

int	free_str(char *str)
{
	free(str);
	return (0);
}

int	error(void)
{
	write(2, "Map error\n", 10);
	return (1);
}
