/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 02:39:05 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/06 02:39:05 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	loop_count;
	int	first_value_copy;

	loop_count = 0;
	while (loop_count != (size / 2))
	{
		first_value_copy = tab[loop_count];
		tab[loop_count] = tab[size - 1 - loop_count];
		tab[size - 1 - loop_count] = first_value_copy;
		loop_count++;
	}
}

/*#include <stdio.h>
int main(void)
{
	int	size;
	int tab[5];

	size = 5;
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab[4] = 5;
	
	for(int i = 0; i < size;i++)
	{
		printf("%d ",tab[i]);
	}
	ft_rev_int_tab(tab, size);
	printf("\n");
	for(int i = 0; i < size;i++)
	{
		printf("%d ",tab[i]);
	}
}*/