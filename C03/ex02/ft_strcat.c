/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:53:47 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/08 01:53:47 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_size;

	dest_size = str_len(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char dest[20] = "voici un";
	char src[10] = " test";
	ft_strcat(dest,src);
	printf("%s",dest);
}*/