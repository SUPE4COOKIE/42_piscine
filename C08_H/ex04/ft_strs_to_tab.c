/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:18:11 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/16 20:26:56 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	new = malloc(str_len(src) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	assign(char *str, struct s_stock_str *str_struct)
{
	str_struct->size = str_len(str);
	str_struct->str = str;
	str_struct->copy = ft_strdup(str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strs_struct;
	int			i;

	strs_struct = malloc(sizeof(t_stock_str) * (ac + 1));
	if (strs_struct == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		assign(av[i], &strs_struct[i]);
		i++;
	}
	strs_struct[i].str = NULL;
	return (strs_struct);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	struct s_stock_str *output = ft_strs_to_tab(argc, argv);
	while (i < argc)
	{
		printf("%s\n%d\n%s\n", output[i].str, output[i].size, output[i].copy);
		i++;
	}
}
