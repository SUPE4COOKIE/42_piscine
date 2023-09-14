/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:41:57 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/17 20:30:23 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*tab_final;
	int	i;

	tab_final = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		tab_final[i] = f(tab[i]);
		i++;
	}
	return (tab_final);
}

/*
#include <stdio.h>
int increment(int i)
{
	 return (++i);
}
int main(void)
{
	int (*f)(int) = increment;
	int tab[] = {5,4,3,6,8,7,4,5};
	int *tab2 = ft_map(tab, 6, f);
	int i = 0;
	while (i < 6)
	{
		printf("%d",tab2[i]);
		i++;
	}
}
*/