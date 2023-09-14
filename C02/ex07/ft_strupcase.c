/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:07:38 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/07 01:07:38 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= ('a' - 'A');
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	char	test[] = "this is a test";
	ft_strupcase(test);
	printf("%s",test);
}*/