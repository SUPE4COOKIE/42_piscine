/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 03:02:58 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/08 03:02:58 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		count = 0;
		j = 0;
		while (str[j])
		{
			if (str[i + j] != to_find[j])
				break ;
			count++;
			if (count == str_len(to_find))
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	if (ft_strstr("fdgdchatdfog", "chat") != 0)
	{
		printf("found !");
	}
	else
	{
		printf("not found");
	}
}*/
