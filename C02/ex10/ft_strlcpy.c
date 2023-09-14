/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:53:33 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/07 01:53:33 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_size(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;
	unsigned int	i;

	src_size = str_size(src);
	if (size == 0)
	{
		return (src_size);
	}
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

/*#include <stdio.h>
int	main()
{
	char src[] = "Piano";
	char dest[] = "Hello";
	printf("%d %s", ft_strlcpy(dest, src, 10), dest);
}*/