/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:58:02 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/19 15:55:51 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*#include <stdio.h>
void ft_print(int i)
{
	printf("%d\n",i);
}
int main(void)
{
	void (*f)(int) = ft_print;
	int tab[] = {5,4,3,6,8,7,4,5};
	ft_foreach(tab, 6, f);
}*/