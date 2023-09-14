/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_dict.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:13:15 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/23 22:53:51 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFY_DICT_H
# define VERIFY_DICT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		str_len(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*append(char *str, char c);
typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;
#endif