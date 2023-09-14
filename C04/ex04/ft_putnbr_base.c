/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 03:17:15 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/09 03:17:15 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
	{
		return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long int	nbr_long;

	nbr_long = nbr;
	base_size = str_size(base);
	if (!is_base_valid(base))
		return ;
	if (nbr_long < 0)
	{
		write (1, "-", 1);
		nbr_long *= -1;
	}
	if (nbr_long < base_size)
		write (1, &base[nbr_long], 1);
	if (nbr_long > base_size - 1)
	{
		ft_putnbr_base(nbr_long / base_size, base);
		ft_putnbr_base(nbr_long % base_size, base);
	}
}

/*int main(void)
{
	ft_putnbr_base(123,"a");
}*/
