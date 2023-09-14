/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:33:39 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/06 01:33:39 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*#include <stdio.h>
void	main(void)
{
	int a;
	int b;

	a = 25;
	b = 5;
	ft_ultimate_div_mod(&a,&b);
	printf("a / b = %d\na %% b = %d\n",a,b);
}*/