/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:54:11 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/06 00:54:11 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	a_copy;

	a_copy = *a;
	*a = *b;
	*b = a_copy;
}

/*#include <stdio.h>
void	main()
{
	int a;
	int b;

	a = 4;
	b = 2;
	printf("a:%d b:%d\n",a,b);
	ft_swap(&a,&b);
	printf("a:%d b:%d\n",a,b);
}*/