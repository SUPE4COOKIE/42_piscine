/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:02:45 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/07 01:02:45 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] == 127)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d",ft_str_is_printable("test"));
	printf("%d",ft_str_is_printable("test\n"));
}*/