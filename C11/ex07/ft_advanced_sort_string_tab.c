/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:03:35 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/19 15:54:47 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	is_sorted;

	j = 0;
	while (tab[j])
	{
		i = 0;
		is_sorted = 1;
		while (tab[i] && tab[i + 1])
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				swap(&tab[i], &tab[i + 1]);
				is_sorted = 0;
			}
			i++;
		}
		if (is_sorted)
			break ;
		j++;
	}
}

/*
int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
int main(void)
{
    char *tab[] = {"Bonjour","Albert","ceci","est", "un","test",NULL};

    ft_advanced_sort_string_tab(tab, ft_strcmp);

    int i = 0;
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }

    return 0;
}*/