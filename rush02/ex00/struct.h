/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:59:41 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/23 17:24:43 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		str_len(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_number(char *str);
char	*sanitize(char *str);
typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;
#endif