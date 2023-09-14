/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 03:20:13 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/10 03:20:13 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	if (nb <= 1 || !(nb % 2))
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (!(nb % i))
			return (0);
		i += 1;
	}
	return (1);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d", ft_is_prime(3));
}*/