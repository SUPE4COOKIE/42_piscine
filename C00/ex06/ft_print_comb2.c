/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 03:26:10 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/05 03:26:10 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int *num0, int *num1)
{
	write(1, &num1[0], 1);
	write(1, &num1[1], 1);
	write(1, " ", 1);
	write(1, &num0[0], 1);
	write(1, &num0[1], 1);
	if (num1[0] != '9' || num1[1] != '8' || num0[0] != '9' || num0[1] != '9')
	{
		write(1, ", ", 2);
	}
}

void	increment(int *num)
{
	if (num[1] == '9')
	{
		num[1] = '0';
		num[0]++;
	}
	else
	{
		num[1]++;
	}
}

void	ft_print_comb2(void)
{
	int	num0[2];
	int	num1[2];
	int	loop_count[2];

	loop_count[0] = '0';
	loop_count[1] = '0';
	num1[0] = '0';
	num1[1] = '0';
	while (num1[0] != '9' || num1[1] != '9')
	{
		num0[0] = loop_count[0];
		num0[1] = loop_count[1];
		while (num0[0] != '9' || num0[1] != '9')
		{
			increment(num0);
			print_num(num0, num1);
		}
		increment(num1);
		increment(loop_count);
	}
}
