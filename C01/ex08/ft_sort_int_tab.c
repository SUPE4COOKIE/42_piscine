/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:02:14 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/06 14:46:29 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	repeat;
	int	single;

	repeat = 0;
	single = 0;
	while (repeat < size)
	{
		single = 0;
		while (single < size - repeat - 1)
		{
			if (tab[single] > tab[single + 1])
			{
				swap(&tab[single], &tab[single + 1]);
			}
			single++;
		}
		repeat++;
	}
}

/*
#include <stdio.h>
int main(void)
{
    int t[5] = {10,4,1,3,2};
    int size = 5;
    ft_sort_int_tab(t,size);
    for(int i = 0; i < size;i++)
	{
		printf("%d ",t[i]);
	}
}*/