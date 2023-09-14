/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:22:34 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/07 01:22:34 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char str)
{
	if ('a' <= str && str <= 'z')
	{
		return (1);
	}
	return (0);
}

int	is_uppercase(char str)
{
	if ('A' <= str && str <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	is_separator(char str)
{
	if (!(is_lowercase(str) || is_uppercase(str) || ('0' <= str && str <= '9')))
	{
		return (1);
	}
	return (0);
}

void	lower_case(char *str, int i)
{
	if (i != 0 && !(is_separator(str[i - 1])) && is_uppercase(str[i]))
	{
		str[i] += ('a' - 'A');
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (is_lowercase(str[i]))
	{
		str[i] -= ('a' - 'A');
	}
	while (str[i])
	{
		if (is_separator(str[i]))
		{
			if (is_lowercase(str[i + 1]))
			{
				str[i + 1] -= ('a' - 'A');
			}
		}
		else
		{
			lower_case(str, i);
		}
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	char test[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(test);
	printf("%s",test);
}*/
