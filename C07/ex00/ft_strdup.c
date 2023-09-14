/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:33:37 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/16 17:05:38 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strdup(char *src)
{
	char	*new;

	new = malloc(str_len(src) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, src);
	return (new);
}

/*#include <stdio.h>
int	main(void)
{
	char	src[4] = "test";
	char	*dup;

	dup = ft_strdup(src);
	printf("%s",dup);
	free(dup);
}*/