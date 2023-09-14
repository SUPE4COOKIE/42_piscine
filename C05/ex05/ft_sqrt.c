/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 03:07:36 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/10 03:07:36 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int				range_search_start;
	int				range_search_end;
	int				middle_range;
	long long		result;

	range_search_start = 0;
	range_search_end = nb;
	if (nb == 0 || nb == 1)
		return (nb);
	while (range_search_start <= range_search_end)
	{
		middle_range = range_search_start;
		middle_range += (range_search_end - range_search_start) / 2;
		result = (long long)middle_range * middle_range;
		if (result == nb)
			return (middle_range);
		else if (result < nb)
			range_search_start = middle_range + 1;
		else
			range_search_end = middle_range - 1;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d",ft_sqrt(2147395600));
}*/