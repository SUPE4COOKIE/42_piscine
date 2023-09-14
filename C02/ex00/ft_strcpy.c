/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:53:39 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/08 16:10:58 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char src[40];
	char dest[40];

	ft_strcpy(src, "this is a test");
	printf("%s\n", src);
	ft_strcpy(dest,src);
	printf("src : %s\ndest:%s",ft_strcpy(dest, "this is a test"), dest);
}*/