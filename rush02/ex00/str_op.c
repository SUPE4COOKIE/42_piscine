/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:36:19 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/23 00:36:19 by mwojtasi         ###   ########.fr       */
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

int	required_space_amount(char *str)
{
	int	i;
	int	nes_count;
	int	count;

	i = 0;
	count = 0;
	nes_count = 0;
	while (str[i] == ' ')
	{
		i++;
		nes_count++;
	}
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
			{
				i++;
				nes_count++;
			}
			count++;
		}
		if (str[i])
			i++;
	}
	if (str[i - 1] == ' ' && count != 0)
		return (nes_count - count - 1);
	return (nes_count - count);
}

char	*sanitize(char *str)
{
	char	*new;
	int		i;
	int		j;

	new = malloc((str_len(str) - required_space_amount(str)));
	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			new[j++] = ' ';
		}
		new[j++] = str[i];
		if (str[i])
			i++;
	}
	if (new[j - 1] == ' ' || new[j - 1] == '\0')
		new[j - 2] = '\0';
	free(str);
	return (new);
}

/*#include <stdio.h>
int main(void)
{
	char *str;
	str = malloc(36);
	ft_strcpy(str, "    Bonjour    test    !    test   ");
	str = sanitize(str);
	printf("%s",str);
	free(str);
	return (0);
}*/
