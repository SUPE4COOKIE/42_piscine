/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_to_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:59:28 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/23 22:51:19 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char	*append(char *str, char c)
{
	int		len;
	char	*new;

	len = str_len(str);
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	ft_strcpy(new, str);
	free(str);
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}

int	count_lines(char *path)
{
	int		fd;
	char	c;
	char	c_previous;
	int		byte_read;
	int		count;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Dict Error\n", 11);
		return (-1);
	}
	byte_read = 1;
	count = 0;
	c_previous = 2;
	while (byte_read > 0)
	{
		byte_read = read (fd, &c, 1);
		if (c == '\n' && c_previous != '\n')
			count++;
		c_previous = c;
	}
	close(fd);
	return (count);
}

void	split(char *str, t_dict *dict_array, int *i, int *j)
{
	if (str_len(str) > 0)
	{
		if (*j % 2 == 0)
			dict_array[*i].key = ft_number(ft_strdup(str));
		else
		{
			dict_array[*i].value = sanitize(ft_strdup(str));
			(*i)++;
		}
		(*j)++;
	}
	free(str);
	str = malloc(1);
	str[0] = '\0';
}

t_dict	*fill_dict(int fd, t_dict *dict_array)
{
	char	c;
	char	*str;
	int		byte_read;
	int		i;
	int		j;

	str = malloc(1);
	str[0] = '\0';
	byte_read = 1;
	i = 0;
	j = 0;
	while (byte_read > 0)
	{
		byte_read = read(fd, &c, 1);
		if (byte_read > 0)
		{
			if (c == ':' || c == '\n')
				split(str, dict_array, &i, &j);
			else
				str = append(str, c);
		}
	}
	free(str);
	return (dict_array);
}

t_dict	*txt_to_dict(char *path)
{
	t_dict	*dict_array;
	int		fd;
	int		lines_count;

	lines_count = count_lines(path);
	if (lines_count > 0)
	{
		dict_array = malloc(sizeof(t_dict) * lines_count);
		fd = open(path, O_RDONLY);
		if (fd == -1 || !dict_array)
		{
			write(2, "Dict Error\n", 11);
			return (NULL);
		}
		fill_dict(fd, dict_array);
		return (dict_array);
	}
	else
		return (NULL);
}

#include <stdio.h>
int	main(void)
{
	t_dict	*dict_array;
	int	i = 0;
	dict_array = txt_to_dict("numbers.dict");
	if (dict_array == NULL)
		return (0);
	//int lines_count = count_lines("numbers.dict");
	while (i < count_lines("numbers.dict"))
	{
		printf("Key: %s, Value: %s\n", dict_array[i].key, dict_array[i].value);
		i++;
	}
	for (i = 0; i < count_lines("numbers.dict"); i++)
	{
		free(dict_array[i].key);
		free(dict_array[i].value);
	}
	free(dict_array);
	return 0;
}