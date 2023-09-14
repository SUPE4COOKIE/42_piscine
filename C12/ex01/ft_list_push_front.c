/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:38:53 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/07/20 02:38:53 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem)
	{
		elem->next = *begin_list;
		*begin_list = elem;
	}
}

#include <stdio.h>
void printLinkedlist(t_list *p)
{
  while (p != NULL)
  {
    printf("%d ", *(int*)p->data);
    p = p->next;
  }
}
int    main(void)
{
    t_list    **elem;
	int			data0 = 9;
    int			data1 = 15;
	int 		data2 = 12;

    elem = malloc(3 * sizeof(t_list));
	ft_list_push_front(&elem[1], &data1);
	ft_list_push_front(&elem[2], &data2);
    ft_list_push_front(&elem[1], &data1);
	printLinkedlist(*elem);
    return (0);

}