/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 02:09:45 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/27 02:09:45 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_whitespace(char c);
int		str_len(char *str);
int		is_base_valid(char *base);
int		get_val(char c, char *base);
int		int_len(int nbr, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sign;

	sign = 1;
	i = 0;
	result = 0;
	if (!is_base_valid(base))
		return (0);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && get_val(str[i], base) != -1)
	{
		result = result * str_len(base) + get_val(str[i], base);
		i++;
	}
	return (result * sign);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	len = str_len(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(int nbr, char *base, int i, int sign)
{
	char	*result;
	int		len_result;

	len_result = int_len(nbr, base);
	result = malloc(sizeof(char) * (len_result + 1));
	while (i < len_result)
	{
		if (nbr < 0)
		{
			result[i] = base[-(nbr % str_len(base))];
			nbr = -(nbr / str_len(base));
			sign = -1;
		}
		else if (nbr == 0 && sign == -1)
			result[i] = '-';
		else
		{
			result[i] = base[nbr % str_len(base)];
			nbr /= str_len(base);
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_int;
	char	*nb_base;

	if (!is_base_valid(base_to))
		return (NULL);
	else if (!is_base_valid(base_from))
		return (NULL);
	nb_int = ft_atoi_base(nbr, base_from);
	nb_base = ft_itoa_base(nb_int, base_to, 0, 1);
	nb_base = ft_strrev(nb_base);
	return (nb_base);
}

/*#include <stdio.h>
int main()
{
	char *base_from = "0123456789";
	char *base_to = "0123456789abcdef";
	char *nbr = "42";
	char *result = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", result);
	return (0);
}*/