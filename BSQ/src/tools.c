/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:26:55 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 18:45:04 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "prototypes.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (!str[i] && nb != 0)
		return (nb);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*append(char *str, char c)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	ft_strcpy(new, str);
	free(str);
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}

t_tile	*ft_strdup(char *src, int size_read, t_map *map)
{
	t_tile	*dest;
	int		i;

	if (size_read != map->length)
		return (NULL);
	dest = malloc(sizeof(t_tile) * (size_read));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size_read - 1)
	{
		if (!is_possible(src[i], map))
		{
			free(dest);
			return (NULL);
		}
		dest[i].value = src[i];
		dest[i].max_square = -1;
		i++;
	}
	return (dest);
}
