/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 02:09:47 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/27 02:09:47 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		||c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || is_whitespace(base[i]))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	get_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	int_len(int nbr, char *base)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len += 1;
		nbr /= str_len(base);
		nbr *= -1;
		if (nbr != 0)
			len++;
	}
	while (nbr >= str_len(base))
	{
		nbr /= str_len(base);
		len++;
	}
	return (len);
}
