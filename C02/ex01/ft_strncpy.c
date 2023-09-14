/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:06:05 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/07 19:13:51 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int main(void)
{
	char src[40];
	char dest[40];

	ft_strncpy(src, "this is a test",9);
	printf("%s\n", src);
	ft_strncpy(dest,src,6);
	printf("src : %s\ndest: %s",src, dest);
}*/
