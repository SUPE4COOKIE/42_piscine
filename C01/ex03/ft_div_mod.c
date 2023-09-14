/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:25:23 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/06 01:25:23 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>
void	main(void)
{
	int div;
	int mod;
	ft_div_mod(25, 5, &div, &mod);
	printf("div: %d mod: %d\n",div,mod);
}*/