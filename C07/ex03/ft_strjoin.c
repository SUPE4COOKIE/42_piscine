/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:29:54 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/12 03:29:54 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	all_str_len(int size, char **strs, int sep_size)
{
	int	i;
	int	j;
	int	total_count;

	total_count = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			total_count++;
			i++;
		}
		j++;
	}
	return (total_count + ((j - 1) * sep_size) + 1);
}

int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src, char *sep)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_size;

	dest_size = str_len(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	if (sep != NULL)
	{
		j = 0;
		while (sep[j])
		{
			dest[dest_size] = sep[j];
			j++;
			dest_size++;
		}
	}
	dest[dest_size] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_str;
	int		i;

	if (size == 0)
	{
		final_str = malloc(sizeof(char));
		*final_str = '\0';
		return (final_str);
	}
	final_str = malloc(all_str_len(size, strs, str_len(sep)));
	if (final_str == NULL)
		return (NULL);
	final_str[0] = '\0';
	i = 0;
	while (i < size)
	{
		if (i != (size - 1))
			ft_strcat(final_str, strs[i], sep);
		else
			ft_strcat(final_str, strs[i], NULL);
		i++;
	}
	return (final_str);
}

/*#include <stdio.h>
int main(int argc, char *argv[])
{
	printf("%s", ft_strjoin(argc, argv, "::"));
}*/
