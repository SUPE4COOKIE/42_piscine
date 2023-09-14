/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:28:05 by arvoyer           #+#    #+#             */
/*   Updated: 2023/07/25 16:54:52 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int		is_possible(char c, t_map *map);
int		ft_atoi(char *str);
int		read_first_line(char *filename, t_map *map);
t_tile	**save_file(char *filename, t_map *map);
void	*free_map(t_tile **board, int size);
t_map	*read_file(char *filename);
int		recursive(t_map *map, int i, int j);
t_tile	*ft_strdup(char *src, int size_read, t_map *map);
char	*ft_strcpy(char *dest, char *src);
char	*append(char *str, char c);
int		ft_strlen(char *str);
t_map	*read_term(void);
int		free_str(char *str);
int		error(void);

#endif
