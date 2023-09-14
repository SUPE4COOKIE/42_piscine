/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:52:50 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/07 18:39:41 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	is_unprintable(char c)
{
	if (c < ' ' || c == 127)
	{
		return (1);
	}
	return (0);
}

char	*dec_to_hex(char c, char *rtn)
{
	char	hex_values[16];

	ft_strcpy(hex_values, "0123456789abcdef");
	rtn[0] = hex_values[c / 16];
	rtn[1] = hex_values[c % 16];
	return (rtn);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	rtn[2];

	i = 0;
	while (str[i])
	{
		if (is_unprintable(str[i]))
		{
			write(1, "\\", 2);
			write(1, dec_to_hex(str[i], rtn), 2);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

/*
#include <stdio.h>
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}*/
