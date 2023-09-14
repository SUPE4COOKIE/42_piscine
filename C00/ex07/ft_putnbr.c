/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:30 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/05 18:33:55 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	int_size(int number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

int	divisor_max_size(int int_size)
{
	int	num;

	num = 1;
	while (int_size - 1 != 0)
	{
		num *= 10;
		int_size--;
	}
	return (num);
}

void	print_putnbr(char num, int *negative)
{
	if (*negative)
	{
		*negative = 0;
		write(1, "-", 1);
	}
	write(1, &num, 1);
}

void	ft_putnbr(int nb)
{
	int		nb_size;
	char	byte_number;
	int		divisor;
	int		negative;

	nb_size = int_size(nb);
	divisor = divisor_max_size(nb_size);
	if (nb < 0)
	{
		divisor *= -1;
		negative = 1;
	}
	while (nb_size != 0)
	{
		byte_number = (nb / divisor) % 10 + 48;
		print_putnbr(byte_number, &negative);
		nb_size--;
		divisor = divisor / 10;
	}
}
