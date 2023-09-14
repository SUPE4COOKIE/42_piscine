/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:03:21 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/09 14:49:09 by mwojtasi         ###   ########.fr       */
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
	while (int_size - 1 > 0)
	{
		num *= 10;
		int_size--;
	}
	return (num);
}

int	case_zero(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	int		nb_size;
	char	byte_number;
	int		divisor;

	nb_size = int_size(nb);
	divisor = divisor_max_size(nb_size);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (case_zero(nb))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb_size--)
	{
		byte_number = (nb / divisor) % 10 + 48;
		write(1, &byte_number, 1);
		divisor /= 10;
	}
}

/*int	main()
{
	ft_putnbr(0);
}*/
