/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 01:45:27 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/18 01:45:27 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*int contain_A(char* str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'A')
			return (1);
		i++;
	}
	return (0);
}

#include <stdio.h>
int main(void)
{
	char *string[] = {"hallo", "Abraham", 0};
	int (*f)(char*) = contain_A;
	printf("%d\n", ft_count_if(string, 2, f));
}*/