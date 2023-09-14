/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:18:09 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/19 16:57:03 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_authorized_char(char c, int has_already_been_number)
{
	if ((c == '+' || c == '-' || c == ' ' || c == '\t'
			||c == '\n' || c == '\v' || c == '\f'
			|| c == '\r') && !has_already_been_number)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	int	has_already_been_number;

	i = -1;
	sign = 1;
	result = 0;
	has_already_been_number = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			sign *= -1;
		else if ('0' <= str[i] && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			has_already_been_number = 1;
		}
		else if (!is_authorized_char(str[i], has_already_been_number))
			break ;
		if (has_already_been_number && (str[i] == '-' || str[i] == '+'))
			break ;
	}
	return (result * sign);
}
