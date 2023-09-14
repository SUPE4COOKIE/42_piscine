/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 02:47:57 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/16 18:45:11 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

#include <stdio.h>
int main(void)
{
	int *tab;
	int i;
	int min;
	int max;

	min = -500;
	max = -300;
	i = 0;
	tab = ft_range(min, max);
	//while (i < (max - min))
	//{
	//	//printf("%d\n", tab[i]);
	//	i++;
	//}
	//return (0);
}