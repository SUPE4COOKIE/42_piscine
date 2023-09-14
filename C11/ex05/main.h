/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:08:55 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/19 14:49:18 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>

int		ft_atoi(char *str);
int		add(int a, int b);
int		substract(int a, int b);
int		divide(int a, int b);
int		mod(int a, int b);
int		mult(int a, int b);
void	doop(int (*op[5])(int, int), char op_sign, int a, int b);
#endif