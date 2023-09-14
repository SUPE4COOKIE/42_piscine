/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:57:11 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/16 17:14:23 by mwojtasi         ###   ########.fr       */
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

char	*copy_str(char *str, int start, int len)
{
	char	*str_copy;
	int		i;

	str_copy = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		str_copy[i] = str[start + i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char *str, char *sep)
{
	int		len;
	int		i;
	int		j;
	int		start;
	char	**split;

	len = str_len(str);
	i = 0;
	j = 0;
	start = 0;
	split = malloc(sizeof(char *) * (len / 2 + 2));
	while (str[i])
	{
		if (is_separator(str[i], sep))
		{
			if (i > start)
				split[j++] = copy_str(str, start, i - start);
			start = i + 1;
		}
		i++;
	}
	if (i > start)
		split[j++] = copy_str(str, start, i - start);
	split[j] = NULL;
	return (split);
}

/*#include <stdio.h>
int main(void) {
    char test[] = "bonjour,aurevoir:merci::bonsoir::";
    char sep[] = ",:";
    char **result = ft_split(test, sep);
    int i = 0;
    while (result[i]) {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return 0;
}*/