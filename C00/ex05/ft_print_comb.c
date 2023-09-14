/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 00:50:44 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/05 00:50:44 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int hundred_count, int ten_count, int unit_count)
{
	write(1, &hundred_count, 1);
	write(1, &ten_count, 1);
	write(1, &unit_count, 1);
	if (hundred_count != '7'
		|| ten_count != '8'
		|| unit_count != '9')
	{
		write(1, ", ", 2);
	}
}

void	print_combinations(int starts[], int counts[])
{
	counts[1] = starts[1];
	while (counts[1] <= '8')
	{
		counts[0] = starts[0];
		while (counts[0] <= '9')
		{
			print_number(counts[2], counts[1], counts[0]);
			counts[0]++;
		}
		starts[0]++;
		counts[1]++;
	}
}

void	ft_print_comb(void)
{
	int	starts[3];
	int	counts[3];

	starts[0] = '2';
	starts[1] = '1';
	starts[2] = '0';
	counts[0] = '0';
	counts[1] = '0';
	counts[2] = '0';
	while (counts[2] <= '7')
	{
		print_combinations(starts, counts);
		starts[1]++;
		starts[0] = starts[1] + 1;
		counts[2]++;
	}
}
