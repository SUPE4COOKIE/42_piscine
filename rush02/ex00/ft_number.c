/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:54:25 by lwatelle          #+#    #+#             */
/*   Updated: 2023/07/23 13:43:29 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_isspace(char f)
{
	return (f == '\f'
		|| f == '\n'
		|| f == '\r'
		|| f == '\t'
		|| f == '\v'
		|| f == ' ');
}

int	ft_sizenumber(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (is_isspace(str[i]))
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_number(char *str)
{
	int		i;
	int		j;
	char	*number;

	i = 0;
	j = 0;
	number = (char *) malloc(sizeof(char) * (ft_sizenumber(str) + 1));
	while (is_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0' && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number[j++] = str[i];
		if (!(str[i] >= '0' && str[i] <= '9'))
			return ("error\n");
		i++;
	}
	return (number);
}
