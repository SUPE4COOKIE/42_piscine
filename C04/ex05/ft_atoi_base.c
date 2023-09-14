/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:32:28 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/27 01:17:09 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		||c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || is_whitespace(base[i]))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sign;

	sign = 1;
	i = 0;
	result = 0;
	if (!is_base_valid(base))
		return (0);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && get_val(str[i], base) != -1)
	{
		result = result * str_len(base) + get_val(str[i], base);
		i++;
	}
	return (result * sign);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d",ft_atoi_base("--101101", "01"));
}*/