/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:43:09 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/19 03:48:35 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_params(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (argv[2][0] == '/' && argv[3][0] == '0' && !argv[3][1])
	{
		write(1, "Stop : division by zero", 23);
		return (0);
	}
	if (argv[2][0] == '%' && argv[3][0] == '0' && !argv[3][1])
	{
		write(1, "Stop : modulo by zero", 21);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	(*op[5])(int, int);

	if (!(check_params(argc, argv)))
		return (0);
	op[0] = add;
	op[1] = substract;
	op[2] = divide;
	op[3] = mod;
	op[4] = mult;
	doop(op, argv[2][0], ft_atoi(argv[1]), ft_atoi(argv[3]));
}
