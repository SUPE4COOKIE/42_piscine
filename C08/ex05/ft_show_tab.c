/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:51:00 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/17 01:33:20 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + (n % 10));
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, str_len(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}

/*
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

int main(int argc, char **argv)
{
	int i = 0;
	ft_show_tab(ft_strs_to_tab(argc, argv));
}
*/
