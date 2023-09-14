/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:43:59 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/20 16:35:37 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar('0' + (num % 10));
}

void	doop(int (*op[5])(int, int), char op_sign, int a, int b)
{
	if (op_sign == '+')
		ft_putnbr(op[0](a, b));
	else if (op_sign == '-')
		ft_putnbr(op[1](a, b));
	else if (op_sign == '/')
		ft_putnbr(op[2](a, b));
	else if (op_sign == '%')
		ft_putnbr(op[3](a, b));
	else if (op_sign == '*')
		ft_putnbr(op[4](a, b));
	else
		ft_putnbr(0);
}
