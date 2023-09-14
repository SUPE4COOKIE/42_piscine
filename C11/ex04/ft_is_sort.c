/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 01:57:25 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/18 01:57:25 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc_sorted;
	int	des_sorted;

	i = 0;
	asc_sorted = 1;
	des_sorted = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			asc_sorted = 0;
		}
		i++;
	}
	while (i >= 0)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			des_sorted = 0;
		}
		i--;
	}
	return (asc_sorted || des_sorted);
}

/*int	nbrcmp(int nb, int nb2)
{
	return (nb - nb2);
}

#include <stdio.h>
int main(void)
{
	int tab[] = {100,10,5,4,1,-5};
	printf("%d", ft_is_sort(tab, 5, nbrcmp));
}*/
